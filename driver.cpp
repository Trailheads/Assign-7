#include "hmap_simple.h"
#include "hmap_smart.h"
#include <iostream>
#include <cassert>


int main(int argc, char **argv) {
    //To prevent segmentation fault, make sure at least one word was passed to the command line
    assert (argv[1] != nullptr);

    /*DEBUG: Print command line arguments
    for(int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }*/


    //Test simple hash table
    hmap_simple simple;

    //Pass command line arguments through hash and insert function
    for(int i = 1; i < argc; ++i) {
        simple.hash(argv[i]);
    }

    simple.print();

    bool does_contain = false;
    std::string first_command_line_word = argv[1];

    //Search for a word that DOES exist in the table.
    does_contain = simple.contains(first_command_line_word);
    std::cout << "Does the simple hash table contain " << argv[1] << "?: " << does_contain << std::endl;

    //Search for a word that DOES NOT exist in the table.
    std::string test_word = "foobarfoo";
    does_contain = simple.contains(test_word);
    std::cout << "Does the simple hash table contain " << test_word << "?: " << does_contain << std::endl;



    

    //Test the smart hash table
    hmap_smart smart_hash;
    int smart_hash_capacity = smart_hash.get_table().capacity();
    std::string command_line_words;

    //Pass command line arguments into double-hash and insert function
    for(int i = 1; i < argc; ++i) {
        command_line_words = (std::string)argv[i];
        smart_hash.hash_function1(&command_line_words);
    }

    //Print table
    smart_hash.print();

    //Search for a word that DOES exist in the table
    does_contain = false;
    does_contain = smart_hash.contains(first_command_line_word);
    std::cout << "Does smart_hash contain the word 'hello'?: " << does_contain << std::endl;

    //Search for a word that DOES NOT exist in the table
    does_contain = smart_hash.contains("world");
    std::cout << "Does smart_hash contain the word 'world'?: " << does_contain << std::endl;

    //Remove a word that DOES exist in the table
    std::string removed_value;
    removed_value = smart_hash.remove(first_command_line_word);
    std::cout << "The word '" << removed_value << "' has been removed" << std::endl;

    //Remove a word that DOES NOT exist in the table
    removed_value = smart_hash.remove(test_word);
    std::cout << "The word '" << removed_value << "' has been removed" << std::endl;

    smart_hash.print();
}