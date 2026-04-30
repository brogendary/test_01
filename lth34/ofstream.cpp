#include <iostream>
#include <fstream>
using namespace std;

main()
{
    ofstream myFile;
    
    // ios::out = operasi output, default;
    // ios::app = menuliskan pada baris akhir;
    // ios::trunc = default, membuat file jika tidak ada, dan kalau ada akan dihapus;

    int a = 123456789;
    myFile.open("data1.txt", ios::out);
    myFile << "Lmao dh ada filenya ";
    myFile << a;
    myFile.close();

    myFile.open("data2.txt", ios::app);
    myFile << "\nLmao dh ada file ke-2 ";
    myFile.close();

    myFile.open("data3.txt", ios::trunc);
    myFile << "\nLmao dh ada file ke-3 ";
    myFile.close();


    return 0;
}