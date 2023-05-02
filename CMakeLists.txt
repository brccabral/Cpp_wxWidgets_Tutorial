cmake_minimum_required(VERSION 3.21.2)
project(VideowxWdgets)

include(GNUInstallDirs)

add_executable(wxExample cApp.cpp cMain.cpp cEditorFrame.cpp cCanvas.cpp)
install(TARGETS wxExample)

#set(wxWidgets_ROOT_DIR "D:\\path\\to\\wxWidgets")
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
target_link_libraries(wxExample PRIVATE ${wxWidgets_LIBRARIES})

message("wxWidgets_USE_FILE=${wxWidgets_USE_FILE}")
message("wxWidgets_LIBRARIES=${wxWidgets_LIBRARIES}")

if(WIN32)

message("CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}")
# https://cmake.org/cmake/help/latest/prop_tgt/WIN32_EXECUTABLE.html
if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
set_target_properties(wxExample PROPERTIES WIN32_EXECUTABLE $<CONFIG:Release>)
else()
set_target_properties(wxExample PROPERTIES WIN32_EXECUTABLE $<CONFIG:Debug>)
endif()

endif()