cmake_minimum_required(VERSION 3.16)

project(DatabaseGamesApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DatabaseGamesApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resources.qrc
        ImagePickerDialog.h
        ImagePickerDialog.cpp
        addgamedialog.h addgamedialog.cpp addgamedialog.ui
        editgamedialog.h editgamedialog.cpp editgamedialog.ui
        utils.h
        utils.cpp


    )
else()
    if(ANDROID)
        add_library(DatabaseGamesApp SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(DatabaseGamesApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Připojení knihoven (sjednocené použití klíče PRIVATE)
target_link_libraries(DatabaseGamesApp
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    PRIVATE Qt${QT_VERSION_MAJOR}::Sql
)

set_target_properties(DatabaseGamesApp PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS DatabaseGamesApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DatabaseGamesApp)
endif()
