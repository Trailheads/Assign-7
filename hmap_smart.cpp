#include "hmap_smart.h"
#include <exception>


hmap_smart::hmap_smart() {
    hash_table.resize(100);
}


hmap_smart::~hmap_smart() {

}


void hmap_smart::hash_function1(std::string *value) {
    std::string val = *value;
    int hashed_key1 = 0;
    int ascii_value = 0;
    const int key_length = value->size();

    //convert each letter in the key to ascii values
    //convert the letters to lowercase values
    //sum each letter's value
    for(int i = 0; i < key_length; ++i) {
        ascii_value = (int)val[i] - 96;

        if(ascii_value < 0) {
            ascii_value += 32;
        }

        hashed_key1 += ascii_value;
    }
    hashed_key1 = hashed_key1 % hash_table.capacity();

    int hashed_key2 = hashed_key1;
    hash_function2(&hashed_key2);
    insert(*value, hashed_key1, hashed_key2);
}


void hmap_smart::hash_function2(int *key) {
    int hashed_key = 0;
    int prime = 27;
    
    hashed_key = prime - (*key % prime);
    *key = hashed_key;
}


void hmap_smart::insert(std::string value, int hashed_key, int hashed_key2) {
    int index = hashed_key;

    //double hash-chain technique: 
    if(hash_table[index] != "") {
        int index2 = hashed_key2;

        for(int i = 0; i < hash_table.capacity(); ++i) {
            int incremented_index = ((index + i) * index2) % hash_table.capacity();

            if(hash_table[incremented_index] == "") {
                hash_table[incremented_index] = value;
                return;
            }
        }
    }
    else {
        hash_table[index] = value;
        //std::cout << "word inserted: " << hash_table[index] << std::endl;
    }
}


void hmap_smart::print() {
    std::cout << "\n";

    for(int i = 0; i < hash_table.capacity(); ++i) {
        std::cout << "(" << i << ") " << hash_table[i]  << std::endl;
    }

    std::cout << "\n";
}


bool hmap_smart::contains(const std::string search_word) {
    bool word_found = false;

    for(int i = 0; i < hash_table.capacity(); ++i) {
        if(hash_table[i] == search_word) {
            word_found = true;
        }
    }

    return word_found;
}


std::string hmap_smart::remove(const std::string remove_word) {
    std::string save_remove_word = "N/A";

    for(int i = 0; i < hash_table.capacity(); ++i) {
        if(hash_table[i] == remove_word) {
            save_remove_word = hash_table[i];
            hash_table[i] = "";
        }
    }

    if(save_remove_word == "N/A") {
        std::cout << "\nThe word '" << remove_word << "' does not exist in the table" << std::endl;
    }

    return save_remove_word;
}


std::vector<std::string> hmap_smart::get_table() const {
    return hash_table;
}