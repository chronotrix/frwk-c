
set(SRC 
    ${SRCPATH}/window.c
)

set(INC 
    ${INCPATH}/export.h
    ${INCPATH}/window.h
)

cppr_add_library(cppr_platform
    SOURCES ${SRC} ${INC}
    DEPENDS purpurina_platform)