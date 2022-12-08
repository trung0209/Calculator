#ifndef NODE_H
#define NODE_H

template <class T>
class Node{

    private:
        T data;
        Node<T> *next;
    public:

       Node (T note_data) { // constructor for Node<T> with data
            this->data = note_data;
            this->next = nullptr;
        }

        // getter setter

        void setData(T node_data) {
            this->data = node_data;
        }


        void setNext(Node<T> *nextNode) {
            this->next = nextNode;
        }

        T getData() {
            return this->data;
        }


        Node<T>* getNext() {
            return this->next;
        }

};

#endif // NODE_H
