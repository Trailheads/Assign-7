/*******************************************************************************
** Author: Enzo Flores
** Program: hash_tables
** Description: Values are taken from the terminal and can be used to either
                create a simple or complex hash tables.
*******************************************************************************/

#ifndef HMAP_SIMPLE_H
#define HMAP_SIMPLE_H

#include <string>
#include <iostream>
#include <vector>

class hmap_simple {
    public:
        hmap_simple();
        ~hmap_simple();

        void hash(char* input_string);
        bool contains(std::string search_word);
        void print();

    private:
        void insert(int hash_value, const int length, char *value);
        std::vector<std::string> basic_table;
};

#endif