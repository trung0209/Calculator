#include "linkedlist.h"

template <typename T>
LinkedList<T>::LinkedList() { // Linkedlist constructor
    this->headNode = nullptr;
}

template <typename T>
Node<T>* LinkedList<T>::get_head() {
    return this->headNode;
}

template <typename T>
void LinkedList<T>::add_head(T data) { // add head
    Node<T> *new_node = new Node<T>(data); // create new Node<T> with data
    if (headNode == nullptr) { // if head Node<T> is null set headNode to new Node<T>
        headNode = new_node;
    } else {    // else change pointer of new note point to head Node<T> and head Node<T> set to new Node<T>
        new_node->setNext(headNode);
        headNode = new_node;
    }
}

template <typename T>
void LinkedList<T>::remove_head() { // remove head
    Node<T> *del = headNode;
    headNode = headNode->getNext();
    delete del;
}

template <typename T>
void LinkedList<T>::empty_list() { // empty a list
    Node<T> *traversal = headNode;
    Node<T> *previous = nullptr;
    while (traversal != nullptr) {
        previous = traversal->getNext();
        delete traversal;
        traversal = previous;
    }
    headNode = nullptr;
}
