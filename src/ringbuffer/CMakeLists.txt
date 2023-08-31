file(GLOB SOURCES "./*.c" "./*.cpp")

add_library(ringbuffer STATIC ${SOURCES})
target_include_directories(ringbuffer PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${PROJECT_SOURCE_DIR}/include/ringbuffer)
