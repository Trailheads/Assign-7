#include "hmap_simple.h"


hmap_simple::hmap_simple() {
    basic_table.resize(100);
}


hmap_simple::~hmap_simple() {
   
}


void hmap_simple::hash(char *input_string) {
    int const string_length = strlen(input_string);
    int char_ascii_value = 0;
    int result = 0;

    //correct uppercase to lowercase values
    if(char_ascii_value < 0) {
        char_ascii_value += 32;
    }

    //adding the accumalative sum of each charater's ascii value
    for(int i = 0; i < string_length; ++i) {
        char_ascii_value = (int)input_string[i] - 96;
        result += char_ascii_value;
    }

    insert(result, string_length, input_string);
}


bool hmap_simple::contains(std::string search_word) {
    bool search_word_found = false;

    for(int i = 0; i < basic_table.size(); ++i) {
        if(basic_table[i] == search_word) {
            search_word_found = true;
        }
    }

    return search_word_found;
}


void hmap_simple::print() {
    const int capacity = basic_table.capacity();

    for(int i = 0; i < capacity; ++i) {
        std::cout << "(" << i << ") " << basic_table[i] << std::endl;
    }
}


void hmap_simple::insert(int hash_key, const int length, char *value) {
    const int table_size = basic_table.capacity();
    std::string word;
    hash_key %= table_size;

    for(int i = 0; i < length; ++i) {
        word += value[i];
    }

    basic_table[hash_key] = word;
    //std::cout << "word inserted: " << basic_table[hash_key] << std::endl;
}