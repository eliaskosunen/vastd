add_subdirectory(cstd)

add_library(vastd SHARED vastd.cpp)
target_link_libraries(vastd cstd)
install(TARGETS vastd DESTINATION lib)
