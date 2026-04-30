#include <iostream>
#include <array>
#include <algorithm>

const size_t arraySize = 10;

void printArray(std::array <int, arraySize> &angka){
    std::cout << "array : ";
    for(int &a : angka){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

void printArray(std::array <char, arraySize> &huruf){
    std::cout << "array : ";
    for(char &a : huruf){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}


main(){

std::array <int, arraySize> angka = {9,5,4,1,2,8,6,3,7,0};

int angkaCari = 5;
bool ketemu = false;

std::cout << "mencari angka dalam array diatas" << std::endl;
std::cin >> angkaCari;
std::sort(angka.begin(), angka.end());
ketemu = std::binary_search(angka.begin(), angka.end(), angkaCari);

if(ketemu) {
    std::cout << "ketemu" << std::endl;

} else {
    std::cout << "gk ada" << std::endl;
}

printArray(angka);

return 0;

}