cmake_minimum_required(VERSION 3.20)
project(MAVLinkInspector VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core
    Quick
    Network
    Widgets
)

set(SOURCES
    src/main.cpp
    src/core/MAVLinkConnection.cpp
    src/core/MAVLinkMessageInfo.cpp
)

set(HEADERS
    include/MAVLinkConnection.h
    include/MAVLinkMessageInfo.h
)

set(RESOURCES
    resources/resources.qrc
)

# 단순하게 실행 파일 생성
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${RESOURCES}
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
    ${CMAKE_CURRENT_SOURCE_DIR}/external/mavlink/common
)

# if(WIN32)
#     set_target_properties(${PROJECT_NAME} PROPERTIES
#         WIN32_EXECUTABLE TRUE
#     )
# endif()