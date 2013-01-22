#ifndef STACK_H
#define STACK_H

class Stack{
  public:
    virtual void push( int ) = 0;
    virtual int pop() = 0;
    virtual bool empty() = 0;
    virtual int size() = 0;
};

#endif
