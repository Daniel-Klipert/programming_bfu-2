cmake_minimum_required(VERSION 3.19)

set(PROJECT_NAME qt_app)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(QT_BUILD_NAME "qt-6.12.0-win10-22H2-x64-msvc-194")
set(CMAKE_PREFIX_PATH "./ext/${QT_BUILD_NAME}/lib/cmake/Qt6/")

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

include_directories("inc/")

qt_add_executable(${PROJECT_NAME}
    src/main.cpp
    src/mainwindow.cpp
    inc/mainwindow.h
    src/mainwindow.ui
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt::Core
        Qt::Widgets
)

file(GLOB ALL_DLLS "ext/${QT_BUILD_NAME}/bin/*.dll")
file(COPY ${ALL_DLLS} 
  DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}"
)

file(COPY "ext/${QT_BUILD_NAME}/plugins"
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}
)

# Install
include(GNUInstallDirs)

set(CMAKE_INSTALL_BINDIR "${CMAKE_CURRENT_BINARY_DIR}/Install")
set(CMAKE_INSTALL_LIBDIR "${CMAKE_CURRENT_BINARY_DIR}/Install/lib")
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/Install")

install(TARGETS ${PROJECT_NAME}
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET ${PROJECT_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
