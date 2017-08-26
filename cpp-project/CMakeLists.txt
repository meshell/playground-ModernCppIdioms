cmake_minimum_required (VERSION 2.6)
project (universe)

set(CMAKE_CXX_FLAGS "-lstdc++fs" )
set(CMAKE_CXX_STANDARD 17)

add_library(stdc++fs UNKNOWN IMPORTED)
set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "/usr/lib/gcc/x86_64-linux-gnu/7/libstdc++fs.a")

add_executable(structured_binding src/helpers/helpers.cpp src/Exercises/structured_binding.cpp)
target_link_libraries(structured_binding stdc++fs)

add_executable(init_statements src/helpers/helpers.cpp src/Exercises/init_statements.cpp)
target_link_libraries(init_statements stdc++fs)

