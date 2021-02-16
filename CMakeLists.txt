cmake_minimum_required(VERSION 3.9)

project (cpurpur
		VERSION 0.0.1
		DESCRIPTION "C binding of Purpurina Framework"
		LANGUAGES C)

set(CMAKE_C_STANDARD 11)

#############################################
####		     BASE CONFIG  			 ####
#############################################

# paths
set(C_PURPUR_PATH "${PROJECT_SOURCE_DIR}")
set(C_PURPUR_SRC "${C_PURPUR_PATH}/src/purpur")
set(C_PURPUR_INC "${C_PURPUR_PATH}/include/purpur")
# source groups
set(PURPUR_HEADER_GROUP "Header Files")
set(PURPUR_SOURCE_GROUP "Source Files")
# purpurina-frwk submodule config
set(PURPUR_FRWK_PATH ${PROJECT_SOURCE_DIR}/submodules/purpurina-frwk)


# VERIFICATION
if(NOT EXISTS "${PURPUR_FRWK_PATH}")
	message(FATAL_ERROR "Missing 'submodules/purpurina-frwk' folder.\nDid you forget to clone the purpurina-frwk repository?")
endif()

if(NOT IS_DIRECTORY "${PURPUR_FRWK_PATH}")
	message(FATAL_ERROR "submodules/purpurina-frwk is not valid directory")
endif()


# include the CMake Configuration and Utils files
include(${PURPUR_FRWK_PATH}/cmake/commons.cmake)

#############################################
####		     ADD PACAKGES 			 ####
#############################################

add_subdirectory("${C_PURPUR_PATH}/src")

# install rules
install(DIRECTORY include
        DESTINATION .
        COMPONENT devel
        PATTERN ".svn" EXCLUDE)