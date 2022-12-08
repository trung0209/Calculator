#ifndef MAP_H
#define MAP_H


class Map {
    private:
       char keys[26] = {0};
       double values[26] = {0};

   public:
       // O(1)
       void insert(char key, double value) {
           int index = hash(key);
           values[index] = value;
           keys[index] = key;
       }
       // O(1)
       double get_value(int key) {
           int index = hash(key);
           return values[index];
       }
       // O(1)
       int hash(char key) { // hashing function
           return key-'A';
       }

};

#endif // MAP_H
