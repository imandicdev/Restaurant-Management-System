cmake_minimum_required(VERSION 3.10)
project(RestaurantReservation VERSION 1.0 LANGUAGES CXX)

# Set C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(Reservation Reservation.cpp)

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Windows specific settings - only keep what's necessary
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# Copy data files to build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/layout.txt 
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/layout.txt COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/guest_info.txt 
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/guest_info.txt COPYONLY)

# For MSVC, also copy files to Debug and Release directories
if(MSVC)
    # Copy to Debug directory
    add_custom_command(TARGET Reservation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/layout.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/layout.txt)
    add_custom_command(TARGET Reservation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/guest_info.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/guest_info.txt)
    
    # Copy to Release directory
    add_custom_command(TARGET Reservation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/layout.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release/layout.txt)
    add_custom_command(TARGET Reservation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/guest_info.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release/guest_info.txt)
endif()

# Basic install targets
install(TARGETS Reservation 
        RUNTIME DESTINATION bin)
install(FILES layout.txt guest_info.txt
        DESTINATION bin)

# Simple configuration output
message(STATUS "Restaurant Reservation System")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
