cmake_minimum_required(VERSION 3.22)

project(gpio_lib)

set(CMAKE_C_COMPILER $ENV{HOME}/Tools/gcc-arm/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc)

include_directories(../platform/include)

set(SRC_DIR src)

# Set include directories and sources
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
    ${SRC_DIR}/gpio.c
)

# Create static library
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Configure library compilation options
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})

# Configure additional compilation options, if needed
target_compile_options(${PROJECT_NAME} PRIVATE 
                                        -c 
                                        -mcpu=cortex-m0plus
                                        -std=c11 
                                        -Wall
                                        -mthumb
                                        )

# Configure linking options, if needed
# target_link_libraries(${PROJECT_NAME} ...)

# Configure installation options, if needed
# install(TARGETS ${PROJECT_NAME} DESTINATION lib)
# install(FILES ... DESTINATION include)