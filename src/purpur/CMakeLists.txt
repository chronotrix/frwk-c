
include(${C_PURPUR_PATH}/cmake/helpers.cmake)

set(INCPATH ${C_PURPUR_INC}/config)

set(CONFIG_HEADERS
    ${INCPATH}/api.h
    ${INCPATH}/types.h
    ${INCPATH}/os_detection.h
)

# output directory
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")
# mark to compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# define export symbol prefix
add_definitions(-DCPPR_EXPORTS)

cppr_add_lib_directory(platform)