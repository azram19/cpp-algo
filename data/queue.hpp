#ifndef QUEUE_H
#define QUEUE_H

class Queue{
  public:
    virtual void enqueue( int ) = 0;
    virtual int dequeue() = 0;
    virtual bool empty() = 0;
    virtual int size() = 0;
};

#endif
