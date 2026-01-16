cmake_minimum_required(VERSION 3.20)
project(MAVLinkInspector VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt 정책 설정 추가
if(POLICY CMP0100)
    cmake_policy(SET CMP0100 NEW)
endif()

find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core
    Quick
    Network
    Widgets
)

set(SOURCES
    src/main.cpp
    src/core/MAVLinkConnection.cpp
)

set(HEADERS
    include/MAVLinkConnection.h
)

# 실행 파일 생성
qt_add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

# QML 모듈 추가 - RESOURCE_PREFIX 명시적으로 설정
qt_add_qml_module(${PROJECT_NAME}
    URI MAVLinkInspector
    VERSION 1.0
    RESOURCE_PREFIX /
    QML_FILES
        resources/qml/Main.qml
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Network
    Qt6::Widgets
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/mavlink
)

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()
