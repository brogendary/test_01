#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

struct Mahasiswa
{
    int pk;
    char NIM[20];
    char nama[50];
    char jurusan[50];
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
    cin.getline(inputMahasiswa.nama, 50);
    cout << "Jurusan: ";
    cin.getline(inputMahasiswa.jurusan, 50);
    cout << "NIM: ";
    cin.getline(inputMahasiswa.NIM, 20);

    writeData(data, size+1, inputMahasiswa);

};

void displayDataMahasiswa(fstream &data)
{
    int size = getDataSize(data);
    Mahasiswa showMahasiswa;
    cout << "no.\tpk.\tNIM.\tNama.\tJurusan." << endl;
    for (int i = 1; i <= size; i++)
    {
        showMahasiswa = readData(data, i);
        cout << i << "\t";
        cout << showMahasiswa.pk << "\t";
        cout << showMahasiswa.NIM << "\t";
        cout << showMahasiswa.nama << "\t";
        cout << showMahasiswa.jurusan << endl;
    }
};

void updateRecord(fstream &data)
{
    int nomor;
    Mahasiswa updateMahasiswa;
    cout << "pilih nomor: ";
    cin >> nomor;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    updateMahasiswa = readData(data, nomor);
    cout << "\n\npilihan data: " << endl;
    cout << "Nama: " << updateMahasiswa.nama << endl;
    cout << "jurusan: " << updateMahasiswa.jurusan << endl;
    cout << "NIM: " << updateMahasiswa.NIM << endl;

    cout << "\nMerubah data: " << endl;
    cout << "Nama: ";
    cin.getline(updateMahasiswa.nama, 50);
    cout << "Jurusan: ";
    cin.getline(updateMahasiswa.jurusan, 50);
    cout << "NIM: ";
    cin.getline(updateMahasiswa.NIM, 20);

    writeData(data, nomor, updateMahasiswa);

};

void deleteRecord(fstream &data)
{
    int nomor, size, offset;
    Mahasiswa blankMahasiswa, tempMahasiswa;   
    fstream dataSementara;
    size = getDataSize(data);

    cout << "Hapus nomor: ";
    cin >> nomor;

    writeData(data, nomor, blankMahasiswa);

    dataSementara.open("temp.dat", ios::trunc | ios::out | ios::in | ios::binary);

    offset = 0;
    for (int i = 1; i <= size; i++)
    {
        tempMahasiswa = readData(data, i);

        if(tempMahasiswa.nama[0] != '\0')
        {
            writeData(dataSementara, i - offset, tempMahasiswa);
        }
        else
        {
            offset++;
            cout << "delete item" << endl;
        }
    }

    size = getDataSize(dataSementara);
    data.close();
    data.open("data.bin", ios::trunc | ios::out | ios::binary);
    data.close();
    data.open("data.bin", ios::out | ios::in | ios::binary);

    for(int i = 1; i <= size; i++)
    {
        tempMahasiswa = readData(dataSementara, i);
        writeData(data, i, tempMahasiswa);
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
            displayDataMahasiswa(data);
            updateRecord(data);
            displayDataMahasiswa(data);
            break;
            case DELETE:
            cout << "Hapus data Mahasiswa" << endl;
            displayDataMahasiswa(data);
            deleteRecord(data);
            displayDataMahasiswa(data);
            break;
            default:
            cout << "Pilihan tidak ditemukan" << endl;
            break;
        }
            while(true)
            {
                cout << "Lanjutkan? [y/n] : ";
                cin >> is_continue;

                if(is_continue == 'y' || is_continue == 'Y')
                {
                    pilihan = getOption();
                    break;
                }
                else if(is_continue == 'n' || is_continue == 'N')
                {
                    return 0;
                }
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
