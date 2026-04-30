#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

struct Mahasiswa
{
    int pk;
    string NIM;
    string nama;
    string jurusan;
};

int getOption();
void checkDatabase(fstream &data);

void writeData(fstream &data, int posisi, Mahasiswa &inputMahasiswa)
{
    data.seekp((posisi - 1)*sizeof(Mahasiswa), ios::beg);
    data.write(reinterpret_cast<char*>(&inputMahasiswa),sizeof(Mahasiswa));
};

int getDataSize(fstream &data)
{
    int start, end;
    data.seekg(0, ios::beg);
    start = data.tellg();
    data.seekg(0, ios::end);
    end = data.tellg();
    return (end-start)/sizeof(Mahasiswa);
};

Mahasiswa readData(fstream &data, int posisi)
{   
    Mahasiswa readMahasiswa;
    data.seekg((posisi - 1)*sizeof(Mahasiswa), ios::beg);
    data.read(reinterpret_cast<char*>(&readMahasiswa), sizeof(Mahasiswa));
    return readMahasiswa;
}

void addDataMahasiswa(fstream &data)
{
    Mahasiswa inputMahasiswa, lastMahasiswa;

    int size = getDataSize(data);
    cout << "ukuran data: " << size << endl;

    if(size == 0)
    {
        inputMahasiswa.pk = 1;
    }
    else
    {
        lastMahasiswa = readData(data, size);
        cout << "pk =" <<  lastMahasiswa.pk << endl;
        inputMahasiswa.pk = lastMahasiswa.pk + 1;
    }

   // readData(data, size);
    
    inputMahasiswa.pk = 1;
    cout << "Nama: ";
    getline(cin, inputMahasiswa.nama);
    cout << "Jurusan: ";
    getline(cin, inputMahasiswa.jurusan);
    cout << "NIM: ";
    getline(cin, inputMahasiswa.NIM);

    writeData(data, size+1, inputMahasiswa);

};

void displayDataMahasiswa(fstream &data)
{
    int size = getDataSize(data);
    Mahasiswa showMahasiswa;
    cout << "no.\tpk.\tNIM.\tNama.\tJurusan." << endl;
    for (int i = 0; i <= size; i++)
    {
        showMahasiswa = readData(data, i);
        cout << i << "\t";
        cout << showMahasiswa.pk << "\t";
        cout << showMahasiswa.NIM << "\t";
        cout << showMahasiswa.nama << "\t";
        cout << showMahasiswa.jurusan << endl;
    }
};

int main()
{
    fstream data;
    checkDatabase(data);
    
    
    int pilihan = getOption();
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
            addDataMahasiswa(data);
            break;
            case READ:
            cout << "Tampilkan data Mahasiswa" << endl;
            displayDataMahasiswa(data);
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
            pilihan = getOption();
            
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

void checkDatabase(fstream &data)
{
    data.open("data.bin", ios::out | ios::in | ios::binary);
    
    if (data.is_open())
    {
        cout << "[--database ditemukan--]" << endl;
    }
    else
    {
        cout << "database tidak ditemukan, buat databse baru" << endl;
        data.close();
        data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
    }
}

int getOption()
{
    int input;
//    system("cls");
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
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return input;
}
