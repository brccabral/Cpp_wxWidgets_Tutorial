cmake_minimum_required(VERSION 3.21.2)
project(VideowxWdgets)

include(GNUInstallDirs)

execute_process(COMMAND wx-config --cxxflags 
    RESULT_VARIABLE CMD_RES 
    OUTPUT_VARIABLE wx_CFLAGS 
    ERROR_VARIABLE ERR_VAR 
    OUTPUT_STRIP_TRAILING_WHITESPACE)
message("WX cppflags CMD_RES=${CMD_RES}; ERR_VAR=${ERR_VAR}")
set(CMAKE_CXX_FLAGS "${wx_CFLAGS} ${CMAKE_CXX_FLAGS}")

execute_process(COMMAND wx-config --libs 
    RESULT_VARIABLE CMD_RES 
    OUTPUT_VARIABLE wx_LIBS 
    ERROR_VARIABLE ERR_VAR 
    OUTPUT_STRIP_TRAILING_WHITESPACE)
message("WX libs CMD_RES=${CMD_RES}; ERR_VAR=${ERR_VAR}")

link_libraries(${wx_LIBS})

add_executable(wxExample cApp.cpp cMain.cpp)
install(TARGETS wxExample)

message("wx_CFLAGS=${wx_CFLAGS}")
message("wx_LIBS=${wx_LIBS}")
message("CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")
message("CMAKE_EXE_LINKER_FLAGS=${CMAKE_EXE_LINKER_FLAGS}")