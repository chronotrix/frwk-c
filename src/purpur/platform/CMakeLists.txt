
# includes
ppr_file_list(
    ROOT ${INCPATH}
    OUTPUT INC
    window.h
    export.h
    platform.h
)
ppr_group(${INC} NAME "include")

# sources
ppr_file_list(
    ROOT ${SRCPATH}
    OUTPUT SRC
    window.cpp
    platform.cpp
)
ppr_group(${SRC} NAME "src")


cppr_add_library(cppr_platform
    SOURCES ${SRC} ${INC}
    DEPENDS purpurina_platform
    )