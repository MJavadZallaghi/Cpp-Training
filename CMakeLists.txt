cmake_minimum_required(VERSION 3.10)  # Specify a minimum CMake version

project(cpp_training)  # Replace with your project's name



add_executable(cpp_training tests/mass_spring_damper_control_test_2.cpp src/RateLimiter.cpp src/pid_controller.cpp src/mass_spring_damper.cpp)  # List your source files

target_include_directories(cpp_training PRIVATE include/)

add_executable(test_multi_threat_exec tests/parallel_run_multi_thread.cpp)

target_include_directories(test_multi_threat_exec PRIVATE include/)

add_executable(log_csv_data tests/log_csv_data.cpp)

target_include_directories(log_csv_data PRIVATE include/)

