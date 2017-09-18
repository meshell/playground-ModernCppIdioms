cmake_minimum_required (VERSION 3.8)
project (modern_cpp)

set(CMAKE_CXX_FLAGS "-lstdc++fs" )
set(CMAKE_CXX_STANDARD 17)

add_library(stdc++fs UNKNOWN IMPORTED)
if(EXISTS "/usr/lib/gcc/x86_64-linux-gnu/7/libstdc++fs.a")
    set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "/usr/lib/gcc/x86_64-linux-gnu/7/libstdc++fs.a")
elseif (EXISTS "/usr/lib/gcc/x86_64-linux-gnu/6/libstdc++fs.a")
    set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "/usr/lib/gcc/x86_64-linux-gnu/6/libstdc++fs.a")
else()
    message(ERROR "Could not find experimental filesystem lib.")
endif()


add_executable(structured_binding src/Exercises/structured_binding.cpp)

add_executable(check_structured_bindings src/check_structured_bindings.cpp src/helpers/helpers.cpp)
target_link_libraries(check_structured_bindings stdc++fs)

add_executable(init_statements src/Exercises/init_statements.cpp)
add_executable(init_statements_solution src/Exercises/init_statements_solution.cpp)

add_executable(regex_test src/regex_test.cpp src/Exercises/regex_replace.h src/helpers/helpers.cpp)
target_link_libraries(regex_test stdc++fs)

add_executable(check_init_statements src/check_init_statements.cpp src/helpers/helpers.cpp)
target_link_libraries(check_init_statements stdc++fs)

add_executable(test_measure_duration src/measure_duration_test.cpp src/Exercises/measure_duration.h src/helpers/helpers.cpp)
target_link_libraries(test_measure_duration stdc++fs)

add_executable(test_time_intervals src/test_time_intervals.cpp src/Exercises/time_intervals.h src/helpers/helpers.cpp)
target_link_libraries(test_time_intervals stdc++fs)

add_executable(vector_sorted_insert src/Exercises/vector_sorted_insert.cpp src/helpers/helpers.cpp)
target_link_libraries(vector_sorted_insert stdc++fs)

add_executable(test_optional src/Exercises/test_optional.cpp)
target_include_directories(test_optional PRIVATE src/catch)

add_executable(test_variant src/Exercises/test_variant.cpp)
target_include_directories(test_variant PRIVATE src/catch)

add_executable(filesystem src/Exercises/filesystem.cpp)
target_link_libraries(filesystem stdc++fs)

add_executable(filesystem_solution src/Exercises/filesystem_solution.cpp)
target_link_libraries(filesystem_solution stdc++fs)

add_executable(check_filesystem_exercise src/check_filesystem_exercise.cpp src/helpers/helpers.cpp)
target_link_libraries(check_filesystem_exercise stdc++fs)

add_executable(use_of_any src/Exercises/use_any.cpp)
add_executable(use_of_any_solution src/Exercises/use_any_solution.cpp)

add_executable(check_any src/check_use_of_any.cpp src/helpers/helpers.cpp)
target_link_libraries(check_any stdc++fs)

add_executable(random_numbers src/Exercises/random_numbers.cpp)
