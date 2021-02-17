
include(CMakeParseArguments)

#
# Add Purpurina C directory
#
# @param package_name {STRING}	cmake target name
#
function(cppr_add_lib_directory package_name)

    set(INCPATH ${C_PURPUR_INC}/${package_name})
    set(SRCPATH ${C_PURPUR_SRC}/${package_name})

    add_subdirectory(${package_name})

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

	# Debug post fix
    set_target_properties(${target} PROPERTIES DEBUG_POSTFIX "_dbg")

	# [WIN32] config
    if(PPR_OS_WINDOWS)
        # include the major version number in Windows shared library names (but not import library names)
        set_target_properties(${target} PROPERTIES SUFFIX "${CMAKE_SHARED_LIBRARY_SUFFIX}")	
		if(BUILD_SHARED_LIBS)
			set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
		endif()
    endif()
    
    # [LINUX] set the version and soversion of the target
    set_target_properties(${target} PROPERTIES SOVERSION ${cpurpur_VERSION_MAJOR}.${cpurpur_VERSION_MINOR})
    set_target_properties(${target} PROPERTIES VERSION ${cpurpur_VERSION})

	# [WIN32] Set the target folder for Visual Studio
	set_target_properties(${target} PROPERTIES FOLDER "c_frwk")

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

#
# Add a new C example executable
#
# @param target {TARGET}			cmake target
# @param SOURCES {STRING[]}		list of files
# @param DEPENDS? {(TARGET | STRING)[]}	optional - list of dependencies
#
macro(cppr_add_executable target)

	# Parse arguments
	cmake_parse_arguments(ARGS "" "" "SOURCES;DEPENDS" ${ARGN})

	# With Win32 with don't have a main file
	# add_executable(${target} WIN32 ${ARGS_SOURCES})
	add_executable(${target} ${ARGS_SOURCES})

	# Set the target folder for Visual Studio
	set_target_properties(${target} PROPERTIES FOLDER "c_examples")

	# Set the dev suffix
	set_target_properties(${target} PROPERTIES DEBUG_POSTFIX "_dbg")

	# Set the Visual Studio startup path for debugging
	set_target_properties(${target} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

	if(ARGS_DEPENDS)
		target_link_libraries(${target} PRIVATE ${ARGS_DEPENDS})
	endif()

	# [WIN32]
	if(PPR_OS_WINDOWS AND BUILD_SHARED_LIBS)
		set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
	endif()
endmacro()