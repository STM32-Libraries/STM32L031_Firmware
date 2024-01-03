cmake_minimum_required(VERSION 3.22)

project(platform_lib)

set(CMAKE_C_COMPILER $ENV{HOME}/Tools/gcc-arm/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc)

set(SRC_DIR src)

# Set include directories and sources
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
    ${SRC_DIR}/platform_types.c
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
# target_link_options(${PROJECT_NAME} PRIVATE -specs=nosys.specs)

# Configure installation options, if needed
# install(TARGETS ${PROJECT_NAME} DESTINATION)
# install(FILES ... DESTINATION include)

