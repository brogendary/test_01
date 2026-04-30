#include <iostream>
#include <string>
using namespace std;


struct buah
{
    string nama;
    string warna;
    float berat;
    int harga;
    string rasa; 
};


main()
{
    buah apel;
    buah mangga;

    apel.nama = "==Apel Merah==";
    apel.warna = "merah";
    apel.berat = 250.50f;
    apel.harga = 12000;
    apel.rasa = "manis kesat";

    mangga.nama = "==Mangga Madu==";
    mangga.warna = "kuning muda";
    mangga.berat = 150.50f;
    mangga.harga = 15000;
    mangga.rasa = "manis madu";

    cout << apel.nama << endl;
    cout << apel.warna << endl;
    cout << apel.berat << endl;
    cout << apel.harga << endl;
    cout << apel.rasa << endl;

    cout << " " << endl;
    
    cout << mangga.nama << endl;
    cout << mangga.warna << endl;
    cout << mangga.berat << endl;
    cout << mangga.harga << endl;
    cout << mangga.rasa << endl;


    return 0;
}