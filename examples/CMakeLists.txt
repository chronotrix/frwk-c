
set(EXAMPLES_PATH "${PROJECT_SOURCE_DIR}/examples")


ct_file_list(
    ROOT ${EXAMPLES_PATH}/simple_window
    OUTPUT SRC
    main.c
)

cct_add_executable(c_simple_window
                   SOURCES ${SRC}
                   DEPENDS ctx_platform)
