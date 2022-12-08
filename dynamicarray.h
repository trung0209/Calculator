#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <class T>
class DynamicArray {
    private:
        T *list;
        int current;
        int size;

    public:
        DynamicArray<T>(int number);
        // O(1) O(n) if need to extend the size
        void append(T a);
        // O(1)
        int getLength();
        // O(1)
        T getAt(int i);
};

#endif // DYNAMICARRAY_H
