#include <iostream>
#include <string>
using namespace std;

struct aktor
{
    string nama;
    int tahun_lahir;
};

struct film
{
    string judul;
    string genre;
    int tahun;
    
    aktor pemeran_1;
    aktor pemeran_2;
    
};


main()
{
    aktor aktor1, aktor2;
    film film1, film2;

    aktor1.nama = "Rusdi";
    aktor1.tahun_lahir = 1998;

    aktor2.nama = "si imup";
    aktor2.tahun_lahir = 1999;

    film1.judul = "Kereta Argo Ngawi";
    film1.genre = "Persahabatan";
    film1.tahun = 2021;
    film1.pemeran_1 = aktor1;
    film1.pemeran_2 = aktor2;

    film2.judul = "anggrek mekar";
    film2.genre = "Pemerintahan";
    film2.tahun = 2024;
    film2.pemeran_1 = aktor1;
    film2.pemeran_2 = aktor2;

    cout << "===" << film1.judul << "===" << endl;
    cout << film1.pemeran_1.nama << endl;
    cout << film1.pemeran_2.nama << endl;

    cout << endl;

    cout << "===" << film2.judul << "===" << endl;
    cout << film2.pemeran_1.nama << endl;
    cout << film2.pemeran_2.nama << endl;


    return 0;
}