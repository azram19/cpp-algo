#include "stack.hpp"
#include "array_stack.hpp"

ArrayStack::ArrayStack(){
  a = new int[16];
  length = 16;
}

int ArrayStack::pop(){
  return a[top--];
}

void ArrayStack::push( int v ){
  a[++top] = v;
  if( top == length - 1 ){
    resize();
  }
}

bool ArrayStack::empty(){
  return top < 0;
}

void ArrayStack::resize(){
  int * b = new int[length * 2];

  for( int i = 0; i < length; i++ ){
    b[i] = a[i];
  }

  a = b;
  length *= 2;
}

int ArrayStack::size(){
  return top + 1;
}
