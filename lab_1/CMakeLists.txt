cmake_minimum_required(VERSION 3.5)

project(oop_lab1_remastered VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        actions/actions.cpp
        actions/actions.h
        errors/errors.cpp
        errors/errors.h
        actions/actions_data.h
        figure/figure.h
        figure/figure.cpp
)

include_directories("${CMAKE_CURRENT_LIST_DIR}/actions")
include_directories("${CMAKE_CURRENT_LIST_DIR}/errors")
include_directories("${CMAKE_CURRENT_LIST_DIR}/draw")
include_directories("${CMAKE_CURRENT_LIST_DIR}/figure")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(oop_lab1_remastered
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET oop_lab1_remastered APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(oop_lab1_remastered SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(oop_lab1_remastered
            ${PROJECT_SOURCES}
            actions/actions.cpp
            actions/actions.h
            errors/errors.cpp
            errors/errors.h
            actions/actions_data.h
            figure/figure.h
            figure/figure.cpp
            figure/points.h
            figure/points.cpp
            figure/edges.h
            figure/edges.cpp
            figure/point.h
            figure/point.cpp
            draw/draw_figure.h
            draw/draw_figure.cpp
        )
    endif()
endif()

target_link_libraries(oop_lab1_remastered PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.oop_lab1_remastered)
endif()
set_target_properties(oop_lab1_remastered PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS oop_lab1_remastered
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(oop_lab1_remastered)
endif()
