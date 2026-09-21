# (E) Barsotion 2018-2026

project(barsotion-icm45686)

set(SOURCES
    src/icm45686_barsotion.c
    src/icm45686_fielddecode.c
)

add_library(barsotion-icm45686 STATIC ${SOURCES})

target_include_directories(barsotion-icm45686
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:inc>
)
