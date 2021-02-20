cmake_minimum_required(VERSION 3.9)

project (chronotrix_c
		VERSION 0.0.1
		DESCRIPTION "C binding of Chronotrix Framework"
		LANGUAGES C CXX)

#############################################
####		     BASE CONFIG  			 ####
#############################################

# compiler
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# paths
set(C_CT_PATH ${PROJECT_SOURCE_DIR})
set(C_CT_SRC ${C_CT_PATH}/src/ct)
set(C_CT_INC ${C_CT_PATH}/include/ct)
set(CPP_CT_PATH ${PROJECT_SOURCE_DIR}/dependencies/frwk)

# source groups
set(CT_HEADER_GROUP "Header Files")
set(CT_SOURCE_GROUP "Source Files")

# include the CMake Configuration and Utils files from cpp framework
include(${CPP_CT_PATH}/cmake/config.cmake)
include(${CPP_CT_PATH}/cmake/commons.cmake)
add_subdirectory(${CPP_CT_PATH})

#############################################
####		     OPTIONS	  			 ####
#############################################

option(BUILD_SHARED_LIBS "TRUE = Build Chronotrix as shared libraries; FALSE = Build as static libraries" TRUE)

option(C_CT_EXAMPLES "TRUE = Build the Chronotrix C examples; FALSE = Don't build examples" TRUE)

#############################################
####		     OS CONFIG  			 ####
#############################################

if(CT_OS_WINDOWS)
    set(STATIC_STD_LIBS FALSE CACHE BOOL "TRUE to statically link to the standard libraries, FALSE to use them as DLLs")

    # for VC++, we can apply it globally by modifying the compiler flags
    if(CT_COMPILER_MSVC AND STATIC_STD_LIBS)
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

include(${C_CT_PATH}/cmake/helpers.cmake)

add_subdirectory("${C_CT_SRC}")

if(C_CT_EXAMPLES)
    add_subdirectory(examples)
endif()

# install rules
install(DIRECTORY include
        DESTINATION .
        COMPONENT devel
        PATTERN ".svn" EXCLUDE)