file(GLOB_RECURSE sources_vastd *.cpp)
file(GLOB_RECURSE headers_vastd *.h)

if(WIN32)
    set(EXEC_SUFFIX .exe)
else()
    set(EXEC_SUFFIX)
endif()

add_library(vastd SHARED ${sources_vastd} ${headers_vastd})
add_dependencies(vastd varuna vart)
add_custom_command(
    TARGET vastd POST_BUILD
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/varuna${EXEC_SUFFIX} ARGS ${CMAKE_SOURCE_DIR}/projects/vastd/cstd/cstd.va -emit=llvm-ir -logging=warning
    COMMAND ${CMAKE_COMMAND} ARGS -E copy cstd.vamod ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} ARGS -E remove cstd.vamod
)
install(TARGETS vastd DESTINATION lib)
