cmake_minimum_required(VERSION 3.14)

project(Universal LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Xml Core)

add_executable(Universal
  main.cpp
  xmlwriter.h
  xmlwriter.cpp
  regularexpressiontester.h
  regularexpressiontester.cpp
  metapropertyclass.h
  metapropertyclass.cpp
  signalsender.h
  signalsender.cpp
  signalreceiver.h
  signalreceiver.cpp
  threadworker.h
  threadworker.cpp
)
target_link_libraries(Universal Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS Universal
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
