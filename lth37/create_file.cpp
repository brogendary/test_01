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

Mahasiswa ambilData(int posisi, fstream &myFile)
{
    Mahasiswa bufferData;
    myFile.seekp((posisi-1)*sizeof(Mahasiswa));
    myFile.read(reinterpret_cast<char*>(&bufferData), sizeof(Mahasiswa));

    return bufferData;
}

void menulisData(Mahasiswa &data, fstream &myFile)
{
    myFile.write(reinterpret_cast<char*>(&data), sizeof(Mahasiswa));
}

void menulisDataByPos(int posisi, Mahasiswa &bufferData, fstream &myFile)
{
    myFile.seekg((posisi-1)*sizeof(Mahasiswa));
    myFile.write(reinterpret_cast<char*>(&bufferData), sizeof(Mahasiswa));

}


main()
{
    fstream myFile;
    myFile.open("data.bin", ios::out | ios::in | ios::binary);

    Mahasiswa mahasiswa1, mahasiswa2, mahasiswa3, output;
    
    mahasiswa1.NIM = 12345;
    mahasiswa1.nama = "Putra";
    mahasiswa1.jurusan = "Hukum";

    mahasiswa2.NIM = 12354;
    mahasiswa2.nama = "Pratama";
    mahasiswa2.jurusan = "Elektro";
    
    mahasiswa3.NIM = 13245;
    mahasiswa3.nama = "Peri";
    mahasiswa3.jurusan = "Bisnis";
        
    
    menulisData(mahasiswa1, myFile);
    menulisData(mahasiswa2, myFile);
    menulisData(mahasiswa3, myFile);
    
    mahasiswa2.nama = "lmao";
    menulisDataByPos(2, mahasiswa2, myFile);

    output = ambilData(2, myFile);

    cout << output.NIM << endl;
    cout << output.nama << endl;
    cout << output.jurusan << endl;
    //myFile.close();

    return 0;
}