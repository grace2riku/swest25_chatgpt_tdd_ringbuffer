#include "RingBuffer.h"

RingBuffer::RingBuffer(size_t size) : buffer_(size, 0) {}

void RingBuffer::enqueue(int value) {
    if (isFull()) {
        throw std::runtime_error("Buffer is full");
    }
    buffer_[tail_] = value;
    tail_ = (tail_ + 1) % buffer_.size();
    count_++;
}

int RingBuffer::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Buffer is empty");
    }
    int value = buffer_[head_];
    head_ = (head_ + 1) % buffer_.size();
    count_--;
    return value;
}

bool RingBuffer::isEmpty() const {
    return count_ == 0;
}

bool RingBuffer::isFull() const {
    return count_ == buffer_.size();
}

size_t RingBuffer::availableSpace() const {
    return buffer_.size() - count_;
}
