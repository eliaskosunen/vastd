file(GLOB_RECURSE sources_vastd *.cpp)
file(GLOB_RECURSE headers_vastd *.h)

if(WIN32)
    set(EXEC_SUFFIX .exe)
else()
    set(EXEC_SUFFIX)
endif()

add_library(vastd ${sources_vastd} ${headers_vastd})
add_dependencies(vastd varuna)
install(TARGETS vastd DESTINATION lib)

add_custom_command(
    OUTPUT cstd.vamod
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/varuna${EXEC_SUFFIX} ${CMAKE_SOURCE_DIR}/projects/vastd/cstd/cstd.va -emit=llvm-ir -logging=warning
    COMMAND ${CMAKE_COMMAND} -E copy cstd.vamod ${CMAKE_SOURCE_DIR}
    DEPENDS varuna vastd
    COMMENT Building standard library module...
)
install(FILES cstd.vamod DESTINATION include/varuna)
