#include <stack.h>

template <typename T>
T Stack<T>::peek() { // peek function
    if (this->isEmpty()) {
        return 0;
    }
    return this->list.get_head()->getData();
}

template <typename T>
int Stack<T>::isEmpty() { // check stack is empty
    if (this->list.get_head() == nullptr) {
        return 1;
    }
    return 0;
}

template <typename T>
void Stack<T>::push(T data) { // push function
    list.add_head(data);
}

template <typename T>
void Stack<T>::pop() { // pop function
    if (isEmpty()) {
        // cout << "Stack is empty" << endl;
        return;
    }
    list.remove_head();
}
