cmake_minimum_required(VERSION 3.23)  # Require a minimum version of CMake
project(The_Maze C)                    # Define the project name and language (C)

set(CMAKE_C_STANDARD 17)               # Set the C standard to C17
set(CMAKE_C_STANDARD_REQUIRED ON)      # Enforce the specified C standard

# Find SDL2 package
find_package(SDL2 REQUIRED)            # Locate the SDL2 library, abort if not found

# Include SDL2 directories
include_directories(${SDL2_INCLUDE_DIRS})  # Add SDL2 include directories

# List of source files
set(SOURCES
    main.c                           # Main source file
    # Add other source files here if needed
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})  # Create an executable from the specified sources

# Link SDL2 libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})  # Link SDL2 to the executable

# Enable compiler warnings
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")  # Check if using GCC or Clang
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)  # Enable common warnings
elseif(MSVC)  # Check if using Microsoft Visual Studio Compiler
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)  # Set warning level to 4
endif()
