cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the project name and language
project(Calculator_lang C)

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

file(GLOB SRC_FILES src/*.c)
# Add the source files
add_executable(${PROJECT_NAME}
    ${SRC_FILES}
)

# (Optional) Include header directories
target_include_directories(${PROJECT_NAME} PRIVATE include)
