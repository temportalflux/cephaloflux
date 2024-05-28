zephyr_library()
zephyr_library_sources_ifdef(ENABLED_CEPHALOFLUX src/cephaloflux.c)
zephyr_include_directories(${APPLICATION_SOURCE_DIR}/include)
