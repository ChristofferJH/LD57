﻿cmake_minimum_required (VERSION 3.8)

project ("LD57")

#create a windows build without console and more compiler optimizations when in release mode
  if(${CMAKE_BUILD_TYPE} STREQUAL  "Release" AND WIN32)
  set(BUILD_EXECUTABLE_TYPE "WIN32")
  add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:/O2>")

  else()
  set(BUILD_EXECUTABLE_TYPE " ")
  endif()


#external libraries
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glad)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glm)
include_directories(${PROJECT_SOURCE_DIR}/lib/miniaudio)
include_directories(${PROJECT_SOURCE_DIR}/lib)

#grab all cpp and hpp files in src

file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.hpp" "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable (${PROJECT_NAME} ${BUILD_EXECUTABLE_TYPE} ${SRC_FILES})


target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} glm)

#copy resources into built directory, simple copy in debug mode
if(${CMAKE_BUILD_TYPE} STREQUAL  "Release" AND WIN32)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_directory 
                "${CMAKE_SOURCE_DIR}/res"
                "$<TARGET_FILE_DIR:Game>/res"
                VERBATIM )

else()

file(COPY "res" DESTINATION ${CMAKE_BINARY_DIR})
endif()