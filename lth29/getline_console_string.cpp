#include <iostream>
#include <string>
using namespace std;

main()
{
    string kalimat_input;
    
    cout << "Masukkan kata atau kalimat : " << endl;
    getline(cin, kalimat_input);

    cout << "input anda : " << kalimat_input << endl;

    int posisi = 0;
    int jumlah = 0;

    while(true)
    {
        posisi = kalimat_input.find(" ", posisi + 1);
        jumlah++;
        cout << "posisi : " << posisi << " jumlah : " << jumlah << endl;

        if(posisi < 0)
        {
            break;
        }
    }

    cout << "Jumlah kata : " << jumlah << endl;

    return 0;
}