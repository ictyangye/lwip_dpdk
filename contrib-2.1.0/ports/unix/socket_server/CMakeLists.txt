cmake_minimum_required(VERSION 3.8)

project(socket_server C)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LWIP_CONTRIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../..)
set(LWIP_DIR         ${CMAKE_CURRENT_SOURCE_DIR}/../../../../lwip-2.1.2)

include(${LWIP_CONTRIB_DIR}/ports/CMakeCommon.cmake)

set (LWIP_DEFINITIONS -DLWIP_DEBUG)
set (LWIP_INCLUDE_DIRS
    "${LWIP_DIR}/src/include"
    "${LWIP_CONTRIB_DIR}/"
    "${LWIP_CONTRIB_DIR}/ports/unix/port/include"
    "${LWIP_CONTRIB_DIR}/ports/unix/socket_server"
)

include(${LWIP_CONTRIB_DIR}/ports/unix/Filelists.cmake)
include(${LWIP_CONTRIB_DIR}/Filelists.cmake)
include(${LWIP_DIR}/src/Filelists.cmake)

add_executable(socket_server ${LWIP_CONTRIB_DIR}/ports/unix/socket_server/socket_server.c)
target_include_directories(socket_server PRIVATE ${LWIP_INCLUDE_DIRS} ${DPDK_INCLUDE_DIRS})
target_compile_options(socket_server PRIVATE ${LWIP_COMPILER_FLAGS})
target_compile_definitions(socket_server PRIVATE ${LWIP_DEFINITIONS} ${LWIP_MBEDTLS_DEFINITIONS})
target_link_libraries(socket_server ${LWIP_SANITIZER_LIBS} lwipcontribportunix lwipcore)