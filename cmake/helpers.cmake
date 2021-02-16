
include(CMakeParseArguments)

#
# Add Purpurina C directory
#
# @param package_name {STRING}	cmake target
#
function(cppr_add_directory package_name)

    set(INCPATH ${C_PURPUR_INC}/${package_name})
    set(SRCPATH ${C_PURPUR_SRC}/${package_name})

    add_subdirectory(${C_PURPUR_SRC}/${package_name})

endfunction()

#
# Add Purpurina C library
#
# @param target {TARGET}			cmake target
# @param SOURCES {STRING[]}		list of files
# @param DEPENDS? {(TARGET | STRING)[]}	optional - list of dependencies
#
macro(cppr_add_library target)

	# parse arguments
	cmake_parse_arguments(ARGS "" "" "SOURCES;DEPENDS" ${ARGN})

	# create library target
	add_library(${target} ${ARGS_SOURCES})

	# module export symbol
	string(REPLACE "-" "_" EXPORT_SYMBOL_NAME "${target}")
	string(TOUPPER "${EXPORT_SYMBOL_NAME}" EXPORT_SYMBOL_NAME)
	set_target_properties(${target} PROPERTIES DEFINE_SYMBOL "${EXPORT_SYMBOL_NAME}_EXPORTS")

    if(PPR_OS_WINDOWS)
        # include the major version number in Windows shared library names (but not import library names)
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX "_dbg")
        set_target_properties(${target} PROPERTIES SUFFIX "${CMAKE_SHARED_LIBRARY_SUFFIX}")
    else()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX "_dbg")
    endif()
    
    # [LINUX] set the version and soversion of the target
    set_target_properties(${target} PROPERTIES SOVERSION ${cpurpur_MAJOR}.${cpurpur_MINOR})
    set_target_properties(${target} PROPERTIES VERSION ${cpurpur_MAJOR}.${cpurpur_MINOR}.${cpurpur_PATCH})

	# [WIN32] Set the target folder for Visual Studio
	set_target_properties(${target} PROPERTIES FOLDER "cppr")

	# [MACOS] Set Xcode properties
	# if(PPR_OS_MACOSX AND BUILD_SHARED_LIBS)
	# endif()



	# Add <purpur/../../> as public include directory
	target_include_directories(${target}
							PUBLIC "$<BUILD_INTERFACE:${C_PURPUR_PATH}/include>"
							PRIVATE "${C_PURPUR_PATH}/src")
	target_include_directories(${target} INTERFACE $<INSTALL_INTERFACE:include>)

	# Link libraries libs
	if(ARGS_DEPENDS)
		target_link_libraries(${target} PUBLIC ${ARGS_DEPENDS})
	endif()

	# For static builds we need to define the static flag to proper compilation
	if(NOT BUILD_SHARED_LIBS)
		target_compile_definitions(${target} PUBLIC "PPR_STATIC")
	endif()

    # add install rules
	install(TARGETS ${target}
            RUNTIME DESTINATION "lib${LIB_SUFFIX}" COMPONENT bin
            LIBRARY DESTINATION "lib${LIB_SUFFIX}" COMPONENT bin
            ARCHIVE DESTINATION "lib${LIB_SUFFIX}" COMPONENT devel
            FRAMEWORK DESTINATION "." COMPONENT bin)

endmacro()
