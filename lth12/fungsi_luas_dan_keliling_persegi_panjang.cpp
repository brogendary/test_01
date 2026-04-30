#include <iostream>
using namespace std;

int luas(double panjang, double lebar){
    double hasil_luas;
    hasil_luas = panjang * lebar;
    return hasil_luas;
}

int keliling(double panjang, double lebar){
    double hasil_keliling;
    hasil_keliling = 2 * (panjang + lebar);
    return hasil_keliling;
}

void tampilkan(double hasil_luas, double hasil_keliling){
    cout << "Keliling = " << hasil_luas << endl;
    cout << "Luas = " << hasil_keliling << endl;
}


int main() {

    double panjang, lebar, hasil_luas, hasil_keliling;

    cout << "=====menghitung luas dan keliling persegi panjang=====" << endl;
    cout << "Input panjangnya = ";
    cin >> panjang;
    cout << "Input lebarnya = ";
    cin >> lebar;

    hasil_luas = luas(panjang, lebar);
    hasil_keliling = keliling(panjang, lebar);
    tampilkan(hasil_luas, hasil_keliling);


    return 0;
}