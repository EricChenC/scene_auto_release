cmake_minimum_required(VERSION 3.0)

project(scene_auto_release)

set(DEPS "D:/depend_library")

include_directories(
${DEPS}/glm
)

file(GLOB SOURCE ./*.*)
add_executable(scene_auto_release ${SOURCE})
























