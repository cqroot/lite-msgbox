cmake_minimum_required(VERSION 3.5)

project(
  lite-msgbox
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

execute_process(COMMAND sh ${CMAKE_SOURCE_DIR}/scripts/qss_to_style_h)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES src/main.cpp src/maindialog.cpp src/maindialog.h
                    src/style.h)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(lite-msgbox MANUAL_FINALIZATION ${PROJECT_SOURCES})
else()
  add_executable(lite-msgbox ${PROJECT_SOURCES})
endif()

target_link_libraries(lite-msgbox PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(
  lite-msgbox
  PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
             MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
             MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
             MACOSX_BUNDLE TRUE
             WIN32_EXECUTABLE TRUE)

install(
  TARGETS lite-msgbox
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(lite-msgbox)
endif()
