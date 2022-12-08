#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template <class T>
class LinkedList { // Linked List class
    private:
        Node<T> *headNode;

    public:
        LinkedList();
        Node<T>* get_head();
        // O(1)
        void add_head(T data);
        void remove_head();
        // O(n)
        void empty_list(); // delete all Node<T>
//        void add_head(T data) { // add head
//            Node<T> *new_node = new Node<T>(data); // create new Node<T> with data
//            if (headNode == nullptr) { // if head Node<T> is null set headNode to new Node<T>
//                headNode = new_node;
//            } else {    // else change pointer of new note point to head Node<T> and head Node<T> set to new Node<T>
//                new_node->setNext(headNode);
//                headNode = new_node;
//            }
//        }


//        void remove_head() { // remove head
//            Node<T> *del = headNode;
//            headNode = headNode->getNext();
//            delete del;
//        }

//        void empty_list() { // empty a list
//            Node<T> *traversal = headNode;
//            Node<T> *previous = nullptr;
//            while (traversal != nullptr) {
//                previous = traversal->getNext();
//                delete traversal;
//                traversal = previous;
//            }
//            headNode = nullptr;
//        }
};


#endif // LINKEDLIST_H
