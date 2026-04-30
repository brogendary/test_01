#include <iostream>
using namespace std;

void fungsi(int &b){
    b = 10;
    cout << "alamat b = " << &b << endl;
    cout << "nilai b = " << b << endl;
}

void kuadrat(int &nilaiRef){
    nilaiRef = nilaiRef * nilaiRef;

}


int main() {

    int a = 5;
    cout << "========================================" << endl;
    cout << "alamat a = " << &a << endl;
    cout << "nilai a = " << a << endl;

    cout << "========================================" << endl;
    //fungsi(a);
    kuadrat(a);
    cout << "nilai a = " << a << endl;

    return 0;
}