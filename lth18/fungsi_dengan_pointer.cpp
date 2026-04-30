#include <iostream>
using namespace std;

void fungsi(int *b){
    cout << "====================================" << endl;
    cout << "nilai b = " << b << endl;
    cout << "alamat b = " << &b << endl;

}

void kuadrat(int *valPtr){
    *valPtr = (*valPtr) * (*valPtr);
}


int main(){

    int a = 10;
    cout << "================================================" << endl;
    cout << "Nilai a = " << a << endl;
    cout << "alamat a = " << &a << endl;

    fungsi(&a);
    kuadrat(&a);

    cout << "================================================" << endl;
    cout << "Nilai a = " << a << endl;


    return 0;
}