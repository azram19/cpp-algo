#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "stack.hpp"

class ArrayStack : public Stack {
  public:
    ArrayStack();
    int pop();
    void push( int );
    bool empty();
    int size();
  private:
    int length = -1;
    int top = -1;
    int * a = nullptr;

    void resize();
};

#endif
