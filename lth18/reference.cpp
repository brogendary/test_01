#include <iostream>
using namespace std;

int main(){

    int a = 5;

    cout << "================================================" << endl;
    cout << "alamaat dari a = " << &a << endl;
    cout << "nilai dari a = " << a << endl;

    int &b = a;
    cout << "================================================" << endl;
    cout << "alamat dari b = " << &b << endl;
    cout << "nilai dari b = " << b << endl;

    b = 10;
    cout << "================================================" << endl;
    cout << "nilai dari a = " << a << endl;
    cout << "nilai dari b = " << b << endl;


    return 0;
}