#include <iostream>
using namespace std;

int itung(int a, int b);
void lmao(int hasil);

int main() {
    
    int a, b, hasil;
    cout << "tolong input nilai pertama = ";
    cin >> a;
    cout << "tolong input nilai kedua = ";
    cin >> b;

    hasil = itung(a, b);
    lmao(hasil);

    return 0;
}

int itung(int a, int b){
    int c;
    c = a + b;

    return c;
}

void lmao(int hasil) {
    cout << "nilai a + b = " << hasil;
}