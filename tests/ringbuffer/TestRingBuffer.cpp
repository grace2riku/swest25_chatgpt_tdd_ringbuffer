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

IGNORE_TEST(RingBuffer, Create)
{
  FAIL("RingBuffer Start here!!!");
}

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

TEST(RingBuffer, AvailableSpaceInitial) {
    CHECK_EQUAL(5, buffer->availableSpace());
}

TEST(RingBuffer, AvailableSpaceAfterEnqueue) {
    buffer->enqueue(1);
    CHECK_EQUAL(4, buffer->availableSpace());

    buffer->enqueue(2);
    CHECK_EQUAL(3, buffer->availableSpace());
}

TEST(RingBuffer, AvailableSpaceAfterDequeue) {
    buffer->enqueue(1);
    buffer->enqueue(2);
    buffer->dequeue();

    CHECK_EQUAL(4, buffer->availableSpace());
}