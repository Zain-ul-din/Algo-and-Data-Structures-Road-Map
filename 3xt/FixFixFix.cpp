#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>

int main() {
    size_t size;
    std::cout << "Enter list size: ";
    std::cin >> size;

    std::vector<int> arr;
    arr.reserve(size);

    while(arr.size() < size) {
        int t;
        std::cout << "Enter value for index " << arr.size() + 1 << ": ";
        std::cin >> t;
        if (std::ranges::find(arr, t) == arr.end()) {
            arr.push_back(t);
        } else {
            std::cout << "Invalid! ";
        }
    }
}