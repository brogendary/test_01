#include <iostream>
using namespace std;

int main() {

    int a = 2;
    int b = 5;
    bool hasil1, hasil2;

    //komparasi, relation expression
    //sebanding
    hasil1 = (a == b);
    //tidak sebanding    
    hasil2 = (a != b);
    //lebih kecil dari
    hasil1 = (a < b);
    //lebih besar dari
    hasil2 = (a > b);
    //lebih kecil sama dengan
    hasil1 = (a <= b);
    //lebih besar sama dengan
    hasil2 = (a >= b);
    //menampilkan hasil komparasi

    cout << hasil1 << endl;
    cout << hasil2 << endl;

    return 0;
}