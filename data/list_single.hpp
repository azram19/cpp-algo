#ifndef LIST_SINGLE_H
#define LIST_SINGLE_H

class SingleList {
  public:
    SingleList();
    SingleList( int );

    SingleList * insert( SingleList **, int, int ); //insert at a position
    SingleList * remove( SingleList ** , SingleList *);
    SingleList * find( int );

    SingleList * add( int ); //add to the end
    SingleList * drop(); //drop from the end

    SingleList * head();
    SingleList * tail();

    int size();
    bool empty();

    int value();

    void tailify();
    void dump();
  private:
    int data = 0;
    SingleList * next = nullptr;

    SingleList * rem( SingleList **, SingleList*, SingleList* );
    SingleList * ins( SingleList **, SingleList*, int, int );
};

#endif
