#ifndef STACK_H
#define STACK_H

#include "linkedlist.cpp"

template <class T>
class Stack { // stack class
private:
        LinkedList<T> list;
    public:
        // O(1)
        void push(T data); // push data into stack
        void pop(); // pop item out of stack
        int isEmpty(); // check if stack empty
        T peek(); // get the top item without remove top
};

#endif // STACK_H
