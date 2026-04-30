#include <iostream>
using namespace std;

int main(){

    int a = 5;
    int b = 10;

    int *aPntr = &a;
    int *bPntr = nullptr;
    bPntr = &b;


    cout << "nilai dari a = " << a << endl;
    cout << "alamat dari a = " << aPntr << endl;
    cout << sizeof(int) << endl;
    a = 10;
    cout << "Menambil nilai dari Pointer 'aPntr' = " << *aPntr << endl;

    cout << "=========================================" << endl;

    cout << "nilai dari b = " << b << endl;
    cout << "alamat dari b = " << bPntr << endl;
    cout << sizeof(int) << endl;

    return 0;
}