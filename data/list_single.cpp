#include "list_single.hpp"
#include <iostream>

SingleList::SingleList(){

}

SingleList::SingleList( int v ){
  data = v;
}

int SingleList::size(){
  if( next == nullptr ){
    return 0;
  } else if( next == this ){
    return 1;
  } else{
    return 1 + next -> size();
  }
}

void SingleList::tailify(){
  if( next == nullptr ){ //avoid memory leaks
      next = this;
  }
}

bool SingleList::empty(){
  if( next == nullptr ){
    return true;
  } else {
    return false;
  }
}

int SingleList::value(){
  return data;
}

SingleList * SingleList::add( int v ){
  if( next == nullptr ){
    data = v;
    next = this;

    return this;
  } else if( next == this ){
    SingleList * n = new SingleList( v );

    n -> tailify();
    next = n;

    return n;
  } else {
    return next -> add( v );
  }
}

SingleList * SingleList::drop(){
  if( next == nullptr ){
    return nullptr;
  } else if( next == this ){
    next = nullptr;
    return this;
  } else {
    if( next == next -> tail() ){
      SingleList * n = next -> drop();
      next = this;
      return n;
    } else{
      return next->drop();
    }
  }
}

SingleList * SingleList::insert( SingleList ** l, int v, int index ){
  return this -> ins( l, this, v, index );
}

SingleList * SingleList::remove( SingleList ** l, SingleList * t ){
  return this -> rem( l, this, t );
}

SingleList * SingleList::ins( SingleList ** l, SingleList * p, int v, int index ){
  if( index == 0 ){
    if( next == nullptr ){
      data = v;
      next = this;
      return this;
    } else {
      SingleList * n = new SingleList( v );
      p -> next = n;
      n -> next = this;
      return n;
    }
  } else if( index == 1){
    if( next == nullptr ){
      data = 0;
      next = this;
    }
    if( next == this ){
      return this -> add( v );
    }
    return next -> ins( l, this, v, index - 1 );
  } else {
    if( next == nullptr ){
      data = 0;
      next = this;
      return this -> ins( l, p, v, index );
    } else if( next == this ){
      this -> add( 0 );
      return next -> ins( l, this, v, index - 1);
    } else{
      return next -> ins( l, this, v, index - 1);
    }
  }
}

SingleList * SingleList::rem( SingleList ** l, SingleList * p, SingleList * t ){
  if( this == t ){
    if( next == this ){
      p -> next = p;
    } else{
      p -> next = this -> next;
    }

    return this;
  } else if( next == nullptr){
    return nullptr;
  } else if ( next == this ){
    return nullptr;
  } else {
    return next -> rem( l, this, t );
  }
}

SingleList * SingleList::find( int v ){
  if( next == nullptr ){
    return nullptr;
  } else{
    if( data == v ){
      return this;
    } else if( next == this ){
      return nullptr;
    } else {
      return next -> find( v );
    }
  }
}

SingleList * SingleList::head(){
  if( next == nullptr ){
    return nullptr;
  } else {
    return this;
  }
}

SingleList * SingleList::tail(){
  if( next == nullptr ){
    return nullptr;
  } else if( next == this ){
    return this;
  } else {
    return next -> tail();
  }
}

void SingleList::dump(){
  std::cout << data << " ";
  if( next != nullptr && next != this ){
    next -> dump();
  }
}
