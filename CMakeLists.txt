cmake_minimum_required(VERSION 2.8)

set(PROJECT "GUI-application")
project(${PROJECT})

# 3rd party tools
find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)
find_package(PkgConfig)
pkg_check_modules(GST REQUIRED gstreamer-1.0>=1.4
                               gstreamer-sdp-1.0>=1.4
                               gstreamer-video-1.0>=1.4
                               gstreamer-app-1.0>=1.4)
find_package(Boost COMPONENTS program_options REQUIRED)

# Qt5 includes
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
# Qt5 required definitions
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
qt5_add_resources(QT_RESOURCES qml.qrc)
# Boost includes
include_directories(${Boost_INCLUDE_DIR})

# Comipilation parameters for Qt5
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
# Aditional compiling steps for MOC RCC and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11 -fstrict-aliasing -pedantic-errors -pedantic -Wno-deprecated-declarations -Wno-unused-variable")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_executable(${PROJECT} ${SOURCE_FILES} ${HEADER_FILES} ${QT_RESOURCES})

target_link_libraries(${PROJECT}
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::Qml
    PRIVATE Qt5::Quick
)

# Gstreamer
target_include_directories(${PROJECT} PRIVATE ${GST_INCLUDE_DIRS})
target_compile_options(${PROJECT} PRIVATE ${GST_CFLAGS})
target_link_libraries(${PROJECT} PRIVATE ${GST_LIBRARIES})
# Boost
target_link_libraries(${PROJECT} PRIVATE ${Boost_LIBRARIES})

# Install executable
install(TARGETS ${PROJECT} DESTINATION ${CMAKE_INSTALL_PREFIX})
