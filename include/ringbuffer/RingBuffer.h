#pragma once

#include <vector>
#include <stdexcept>

class RingBuffer {
public:
    RingBuffer(size_t size);
    
    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    bool isFull() const;
    size_t availableSpace() const;

private:
    std::vector<int> buffer_;
    size_t head_ = 0;
    size_t tail_ = 0;
    size_t count_ = 0;
};

