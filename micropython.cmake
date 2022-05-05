add_library(usermod_microecc INTERFACE)

target_sources(usermod_microecc INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/microecc.c
    ${CMAKE_CURRENT_LIST_DIR}/ecc.c
)

target_include_directories(usermod_microecc INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(usermod INTERFACE usermod_microecc)