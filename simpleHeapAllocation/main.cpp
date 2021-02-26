#include <iostream>

int main() {
    int n;
    std::cout<< "n ="<<std::endl;
    std::cin>> n;
    int* array = new int [n];// heap allocation
    for (int i = 0; i < n; ++i) {
        std::cin>>array[i];
    }
    for (int j = 0; j < n; ++j) {
        std::cout << array[j] <<" ";
    }

    return 0;
}
