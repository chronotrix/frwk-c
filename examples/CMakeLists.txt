
set(EXAMPLES_PATH "${PROJECT_SOURCE_DIR}/examples")


ppr_file_list(
    ROOT ${EXAMPLES_PATH}/simple_window
    OUTPUT SRC
    main.c
)

cppr_add_executable(c_simple_window
                   SOURCES ${SRC}
                   DEPENDS cppr_platform)
