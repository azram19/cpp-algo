#include "queue.hpp"
#include "array_queue.hpp"
#include <iostream>

ArrayQueue::ArrayQueue(){
  a = new int [16];
  length = 16;
}

int ArrayQueue::wrap( int index ){
  return index % length;
}

void ArrayQueue::enqueue( int v ){
  a[wrap( tail )] = v;
  n++;

  tail = wrap( tail + 1 );

  if( length == n + 1 ){
    resize();
  }
}

int ArrayQueue::dequeue(){
  int v = a[wrap(head)];

  n--;

  head = wrap(head+1);
  return v;
}

int ArrayQueue::size(){
  return n;
}

bool ArrayQueue::empty(){
  return n  == 0;
}

void ArrayQueue::resize(){
  int * b = new int [ length * 2 ];

  for(int i = 0, j = head; j < length; j++, i++ ){
    b[i] = a[j];
  }

  if( tail < head ){
    for(int i = length, j = 0; j < tail; j++, i++ ){
      b[i] = a[j];
    }
  }

  a = b;

  head = 0;
  tail = n;

  length *= 2;
}
