#include <iostream>
#include <string>



using namespace std;

int getOPtion()
{
    int input;
    system("cls");
    cout << "\n===Program CRUD Data Mahasiswa===" << endl;
    cout << "=================================" << endl;
    
    cout << "1. Tambah data Mahasiswa" << endl;
    cout << "2. Tampilkan data Mahasiswa" << endl;
    cout << "3. Ubah data Mahasiswa" << endl;
    cout << "4. Hapus data Mahasiswa" << endl;
    cout << "5. Selesai" << endl;
    cout << "=================================" << endl;
    cout << "pilih [1-5]? : ";

    cin >> input;

    return input;
}

int main()
{
    int pilihan = getOPtion();
    char is_continue;

    enum option
    {
        CREATE = 1, READ, UPDATE, DELETE, FINISH
    };

    while(pilihan != FINISH)
    {
        

        switch (pilihan)
        {
            case CREATE:
                cout << "Menambah data Mahasiswa" << endl;
                break;
            case READ:
                cout << "Tampilkan data Mahasiswa" << endl;
                break;
            case UPDATE:
                cout << "Ubah data Mahasiswa" << endl;
                break;
            case DELETE:
                cout << "Hapus data Mahasiswa" << endl;
                break;
            default:
                cout << "Pilihan tidak ditemukan" << endl;
                break;
        }
        label_continue:

        cout << "Lanjutkan? [y/n] : ";
        cin >> is_continue;
        if((is_continue == 'y') | (is_continue == 'Y'))
        {
            pilihan = getOPtion();

        } 
        else if((is_continue == 'n') | (is_continue == 'N'))
        {
            break;
        }
        else
        {
            goto label_continue;
        }


    }

    cout << "akhir dari program" << endl;


    return 0;
}