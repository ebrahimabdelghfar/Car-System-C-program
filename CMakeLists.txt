cmake_minimum_required(VERSION 3.15)
set (C_STANDARD 99)
Set(C_STANDARD_REQUIRED ON)
project(CarSystem)

if(EXISTS ${CMAKE_SOURCE_DIR}/src/main.c)
    message(STATUS "main.c exists at ${CMAKE_SOURCE_DIR}/src")
    add_executable(CarSystemMain ${CMAKE_SOURCE_DIR}/src/main.c)
    target_include_directories(CarSystemMain PUBLIC ${CMAKE_SOURCE_DIR}/library)
    add_library(carMode ${CMAKE_SOURCE_DIR}/library/selectEngineMode.c ${CMAKE_SOURCE_DIR}/library/CarMode.h)
    target_include_directories(carMode PUBLIC ${CMAKE_SOURCE_DIR}/library)
    target_link_libraries(CarSystemMain carMode)
else()
    message(FATAL_ERROR  "main.c does not exist at ${CMAKE_SOURCE_DIR}/src")
endif()


