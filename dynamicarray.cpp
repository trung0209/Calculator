#include "dynamicarray.h"

template <typename T>
DynamicArray<T>::DynamicArray(int number){
    list = new T[number]; // create array
    current = 0;               // keep track of current number of element
    size = number;             // size of array
}

// O(1) O(n) if need to extend the size
template <typename T>
void DynamicArray<T>::append(T a) { // add to list
    if (current >= size) { // resize of array if add more than initialize size
        T *new_list = new T[size*2];  // create new array with new size
        size = size*2;
        for (int i = 0; i < current; i++) { // copy from old to new arr
            new_list[i] = list[i];
        }
        delete []list;
        list = new_list; // repointing to new arr
    }
    list[current] = a; // add name to array
    current++;
}

// O(1)
template <typename T>
int DynamicArray<T>::getLength() { // get current length of array
    return current;
}

// O(1)
template <typename T>
T DynamicArray<T>::getAt(int i) { // get item at i position
    return list[i];
}
