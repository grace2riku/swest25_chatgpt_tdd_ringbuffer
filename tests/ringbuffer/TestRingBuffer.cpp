#include "CppUTest/TestHarness.h"
#include "RingBuffer.h"

TEST_GROUP(RingBuffer) {
    RingBuffer* buffer;

    void setup() {
        buffer = new RingBuffer(5);
    }

    void teardown() {
        delete buffer;
    }
};

TEST(RingBuffer, Create)
{
  FAIL("RingBuffer Start here!!!");
}

#if 0
TEST(RingBuffer, EnqueueAndDequeue) {
    buffer->enqueue(1);
    CHECK_EQUAL(1, buffer->dequeue());
}

TEST(RingBuffer, BufferIsEmpty) {
    CHECK_TRUE(buffer->isEmpty());
    buffer->enqueue(1);
    CHECK_FALSE(buffer->isEmpty());
}

TEST(RingBuffer, BufferIsFull) {
    for (int i = 0; i < 5; i++) {
        buffer->enqueue(i);
    }
    CHECK_TRUE(buffer->isFull());
}

TEST(RingBuffer, OverflowThrowsException) {
    for (int i = 0; i < 5; i++) {
        buffer->enqueue(i);
    }
    CHECK_THROWS(std::runtime_error, buffer->enqueue(6));
}

TEST(RingBuffer, UnderflowThrowsException) {
    CHECK_THROWS(std::runtime_error, buffer->dequeue());
}
#endif