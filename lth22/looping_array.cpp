#include <iostream>
#include <array>
using namespace std;

int main() {

    int Anilai[10] = {0,1,2,3,4,5,6,7,8,9};

    for(int nilai : Anilai){
        cout << "address : " << &nilai << " | nilai : " << nilai << endl;
        nilai = 1;
    }

    cout << endl;

    for(int &nilaiRef : Anilai){
        nilaiRef *= 2;
        cout << "address : " << &nilaiRef << " | nilai : " << nilaiRef << endl;
    }

    cout << endl;

    for(int &nilaiRef : Anilai){
        cout << "address : " << &nilaiRef << " | nilai : " << nilaiRef << endl;
    }

    return 0;
}