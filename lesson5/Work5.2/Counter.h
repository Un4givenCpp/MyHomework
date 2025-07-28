#ifndef COUNTER_H
#define COUNTER_H

#include <string>

class Counter {
private:
    int value;

public:
    Counter();
    Counter(int initialValue);

    void increment();
    void decrement();
    int getValue() const;
    void setValue(int newValue);
};

#endif // COUNTER_H#pragma once
