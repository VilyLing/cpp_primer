
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "moduel_a/inc/a.h"
int main(int argc, char *argv[]){

    // std::map<std::string, size_t> word_count;
    // std::set<std::string> exclude = {"The", "But", "And","Or","An","A","the","but","and","or","an","A"};
    // std::string word;
    // while (std::cin >> word) {
    //     if (exclude.find(word) == exclude.end()) {
    //         ++word_count[word];
    //     }
    // }

    // for (const auto &w : word_count) {
    //     std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " :" time") << std::endl; 
    // }

    // moduel_a::myWordCount();
    // moduel_a::addFamily();
    // moduel_a::saveUniqueWords();
    // moduel_a::strLineMap();
    // moduel_a::usePairVector();

    // moduel_a::addFamilyMuilt();


    std::map<std::string, int> word_count;
    using key_type = std::string;

    using return_type = int&;

    key_type word = "hello";
    return_type count_ref = word_count[word];
    count_ref = 5;

    std::cout << word_count[word];

    std::cin.get();
}