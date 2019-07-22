cmake_minimum_required(VERSION 3.12)

project(Project_Ludum)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp StateMachine/StateMachine.cpp StateMachine/StateMachine.h MainMenu/MainMenu.cpp MainMenu/MainMenu.h Settings/Settings.cpp
        Settings/Settings.h GameLevelBuild/GameLevelBuild.cpp GameLevelBuild/GameLevelBuild.h map/map.cpp map/map.h objects/object.h  objects/layer.cpp objects/layer.h
        objects/sprite.cpp objects/sprite.h GlobalVariables.h)


add_executable(Project_Ludum ${SOURCE_FILES})

target_link_libraries(Project_Ludum sfml-graphics sfml-audio sfml-window sfml-system jsoncpp)
