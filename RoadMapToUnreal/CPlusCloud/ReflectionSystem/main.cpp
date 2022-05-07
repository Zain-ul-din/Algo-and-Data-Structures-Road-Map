#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <type_traits>

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::unordered_map<char , int> map; // using hash table
    map ['z'] = 1;
    map ['a'] = 1;
    map ['i'] = 1;
    map ['n'] = 1;

    std::cout << " is array : " << std::is_array<std::unordered_map<char , int>>() << "  \n";

    // standard for_each func
    std::for_each(map.begin() , map.end() , [&](auto& pair){
       std::cout << " " << pair.first << " : " << pair.second << "\n";
    });


    return 0;
}
