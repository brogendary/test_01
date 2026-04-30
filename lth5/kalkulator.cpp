#include <iostream>
using namespace std;

int main() {

    float a,b,hasil;
    char aritmatika;

    cout << "===Calculator===" << endl;
    cout << "Input nilai ke-1 : ";
    cin >> a;

    cout << "Input nilai ke-2 : ";
    cin >> b;

    cout << "Pilih operator (+,-,/,*) : ";
    cin >> aritmatika;

    if(aritmatika == '+') {
        hasil = a + b;
    } else if(aritmatika == '-') {
        hasil = a - b;
    } else if(aritmatika == '/') {
        hasil = a / b;
    } else if(aritmatika == '*') {
        hasil = a * b;
    } else {
        cout << "Operator salah" << endl;
    }
    

    cout << " = " << hasil << endl;


    return 0;
}