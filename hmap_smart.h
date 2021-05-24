#ifndef HMAP_SMART_H
#define HMAP_SMART_H

#include <vector>
#include <iostream>
#include "string"

class hmap_smart {
    public:
        hmap_smart();
        ~hmap_smart();

        void hash_function1(std::string *value);
        void print();
        bool contains(const std::string search_word);
        std::string remove(const std::string remove_word);
        
        std::vector<std::string> get_table() const;
        
    private:
        void hash_function2(int *value);
        void insert(std::string value, int hashed_key, int hashed_key2);
        std::vector<std::string> hash_table;
};

#endif