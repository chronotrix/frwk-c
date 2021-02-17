cmake_minimum_required(VERSION 3.9)

project (cpurpur
		VERSION 0.0.1
		DESCRIPTION "C binding of Purpurina Framework"
		LANGUAGES C CXX)

#############################################
####		     BASE CONFIG  			 ####
#############################################

# compiler
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# paths
set(C_PURPUR_PATH ${PROJECT_SOURCE_DIR})
set(C_PURPUR_SRC ${C_PURPUR_PATH}/src/purpur)
set(C_PURPUR_INC ${C_PURPUR_PATH}/include/purpur)
set(PURPUR_FRWK_PATH ${PROJECT_SOURCE_DIR}/submodules/purpurina-frwk)

# source groups
set(PURPUR_HEADER_GROUP "Header Files")
set(PURPUR_SOURCE_GROUP "Source Files")

# check sub modules
if(NOT EXISTS "${PURPUR_FRWK_PATH}")
	message(FATAL_ERROR "Missing 'submodules/purpurina-frwk' folder.\nDid you forget to clone the purpurina-frwk repository?")
endif()
if(NOT IS_DIRECTORY "${PURPUR_FRWK_PATH}")
	message(FATAL_ERROR "submodules/purpurina-frwk is not valid directory")
endif()

# include the CMake Configuration and Utils files
include(${PURPUR_FRWK_PATH}/cmake/config.cmake)
include(${PURPUR_FRWK_PATH}/cmake/commons.cmake)

add_subdirectory(submodules/purpurina-frwk)

#############################################
####		     OPTIONS	  			 ####
#############################################

option(BUILD_SHARED_LIBS "TRUE = Build Purpurina as shared libraries; FALSE = Build as static libraries" TRUE)

option(C_PURPUR_EXAMPLES "TRUE = Build the Purpurina C examples; FALSE = Don't build examples" TRUE)

#############################################
####		     OS CONFIG  			 ####
#############################################

if(PPR_OS_WINDOWS)
    set(STATIC_STD_LIBS FALSE CACHE BOOL "TRUE to statically link to the standard libraries, FALSE to use them as DLLs")

    # for VC++, we can apply it globally by modifying the compiler flags
    if(PPR_COMPILER_MSVC AND STATIC_STD_LIBS)
        foreach(flag
                CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
                CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
            if(${flag} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
            endif()
        endforeach()
    endif()
endif()

#############################################
####		     ADD PACAKGES 			 ####
#############################################

add_subdirectory("${C_PURPUR_SRC}")

if(C_PURPUR_EXAMPLES)
    add_subdirectory(examples)
endif()

# install rules
install(DIRECTORY include
        DESTINATION .
        COMPONENT devel
        PATTERN ".svn" EXCLUDE)