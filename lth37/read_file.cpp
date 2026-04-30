#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Mahasiswa
{
    int NIM;
    string nama;
    string jurusan;
};




main()
{
    fstream myFile;
    Mahasiswa dataBaca;
    myFile.open("data.bin", ios::in | ios::binary);
    int posisi = 3;
        //cout << sizeof(Mahasiswa) << endl;
    //dataBaca = ambilData(posisi, myFile);

    cout << dataBaca.NIM << endl;
    cout << dataBaca.nama << endl;
    cout << dataBaca.jurusan << endl;

    myFile.close();

    return 0;
}