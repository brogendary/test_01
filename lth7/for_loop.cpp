#include <iostream>
using namespace std;

int main() {

    cout << "for loop test 1-10" << endl;
    for(int a = 1; a <= 10; a++) {
        cout << a << endl;
    }

    cout << "" << endl;

    cout << "for loop 2-10" << endl;
    for(int b = 2; b <= 10; b +=2) {
        cout << b << endl;
    }

    cout << "for loop jumlah" << endl;
    int total = 0;
    for(int c = 1; c <= 10; c++) {
        total += c;
        cout << c << "||" << total << endl; 
    }


    cout << "looping berhasil" << endl;


    return 0;
}