cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_PROJECT_NAME Firmware)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

enable_language(C ASM)

add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# ---------------------------
# ✅ Add AS5600 driver sources
# ---------------------------
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    Drivers/AS5600/src/as5600.c
)

# ---------------------------
# ✅ Add AS5600 include path
# ---------------------------
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    Drivers/AS5600/src
    Drivers/icm20948/src
    Drivers/icm20948/inc
    Drivers/DRV8871/src
)

target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
)

target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
)

list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
)
