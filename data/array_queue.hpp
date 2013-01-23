#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "queue.hpp"

class ArrayQueue : public Queue {
  public:
    ArrayQueue();
    int dequeue();
    void enqueue( int );
    bool empty();
    int size();
  private:
    int length = 0;
    int head = 0;
    int tail = 0;
    int n = 0;
    int * a = nullptr;

    void resize();
    int wrap( int );
};

#endif
