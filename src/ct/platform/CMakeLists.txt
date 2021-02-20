
# includes
ct_file_list(
    ROOT ${INCPATH}
    OUTPUT INC
    window.h
    export.h
    platform.h
)
ct_group(${INC} NAME "include")

# sources
ct_file_list(
    ROOT ${SRCPATH}
    OUTPUT SRC
    window.cpp
    platform.cpp
)
ct_group(${SRC} NAME "src")


cct_add_library(ctx_platform
    SOURCES ${SRC} ${INC}
    DEPENDS chronotrix_platform
    )