cmake_minimum_required(VERSION 3.26)
project(linked-list-viewer)

find_package(Protobuf REQUIRED)
find_library(ABSL_LOG_INTERNAL_CHECK_OP_LIB absl_log_internal_check_op)
find_library(ABSL_LOG_INTERNAL_MESSAGE_LIB absl_log_internal_message)
find_library(ABSL_LOG_INTERNAL_NULLGUARD_LIB absl_log_internal_nullguard)
set(CMAKE_CXX_STANDARD 14)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS proto/node.proto)

add_executable(linked-list-viewer main.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(linked-list-viewer PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(linked-list-viewer protobuf::libprotobuf ${ABSL_LOG_INTERNAL_CHECK_OP_LIB} ${ABSL_LOG_INTERNAL_MESSAGE_LIB} ${ABSL_LOG_INTERNAL_NULLGUARD_LIB})