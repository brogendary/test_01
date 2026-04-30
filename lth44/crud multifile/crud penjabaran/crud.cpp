#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "crud.h"


void crud::writeData(std::fstream &data, int posisi, crud::Mahasiswa &inputMahasiswa)
{
    data.seekp((posisi - 1)*sizeof(crud::Mahasiswa), std::ios::beg);
    data.write(reinterpret_cast<char*>(&inputMahasiswa),sizeof(crud::Mahasiswa));
};

int crud::getDataSize(std::fstream &data)
{
    int start, end;
    data.seekg(0, std::ios::beg);
    start = data.tellg();
    data.seekg(0, std::ios::end);
    end = data.tellg();
    return (end-start)/sizeof(crud::Mahasiswa);
};

crud::Mahasiswa crud::readData(std::fstream &data, int posisi)
{   
    crud::Mahasiswa readMahasiswa;
    data.seekg((posisi - 1)*sizeof(crud::Mahasiswa), std::ios::beg);
    data.read(reinterpret_cast<char*>(&readMahasiswa), sizeof(crud::Mahasiswa));
    return readMahasiswa;
}

void crud::addDataMahasiswa(std::fstream &data)
{
    crud::Mahasiswa inputMahasiswa, lastMahasiswa;

    int size = crud::getDataSize(data);
    std::cout << "ukuran data: " << size << std::endl;

    if(size == 0)
    {
        inputMahasiswa.pk = 1;
    }
    else
    {
        lastMahasiswa = crud::readData(data, size);
        std::cout << "pk =" <<  lastMahasiswa.pk << std::endl;
        inputMahasiswa.pk = lastMahasiswa.pk + 1;
    }

// crud::readData(data, size);
    
    inputMahasiswa.pk = 1;
    std::cout << "Nama: ";
    std::cin.getline(inputMahasiswa.nama, 50);
    std::cout << "Jurusan: ";
    std::cin.getline(inputMahasiswa.jurusan, 50);
    std::cout << "NIM: ";
    std::cin.getline(inputMahasiswa.NIM, 20);

    crud::writeData(data, size+1, inputMahasiswa);

};

void crud::displayDataMahasiswa(std::fstream &data)
{
    int size = crud::getDataSize(data);
    crud::Mahasiswa showMahasiswa;
    std::cout << "no.\tpk.\tNIM.\tNama.\tJurusan." << std::endl;
    for (int i = 1; i <= size; i++)
    {
        showMahasiswa = crud::readData(data, i);
        std::cout << i << "\t";
        std::cout << showMahasiswa.pk << "\t";
        std::cout << showMahasiswa.NIM << "\t";
        std::cout << showMahasiswa.nama << "\t";
        std::cout << showMahasiswa.jurusan << std::endl;
    }
};

void crud::updateRecord(std::fstream &data)
{
    int nomor;
    crud::Mahasiswa updateMahasiswa;
    std::cout << "pilih nomor: ";
    std::cin >> nomor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    updateMahasiswa = crud::readData(data, nomor);
    std::cout << "\n\npilihan data: " << std::endl;
    std::cout << "Nama: " << updateMahasiswa.nama << std::endl;
    std::cout << "jurusan: " << updateMahasiswa.jurusan << std::endl;
    std::cout << "NIM: " << updateMahasiswa.NIM << std::endl;

    std::cout << "\nMerubah data: " << std::endl;
    std::cout << "Nama: ";
    std::cin.getline(updateMahasiswa.nama, 50);
    std::cout << "Jurusan: ";
    std::cin.getline(updateMahasiswa.jurusan, 50);
    std::cout << "NIM: ";
    std::cin.getline(updateMahasiswa.NIM, 20);

    crud::writeData(data, nomor, updateMahasiswa);

};

void crud::deleteRecord(std::fstream &data)
{
    int nomor, size, offset;
    crud::Mahasiswa blankMahasiswa, tempMahasiswa;   
    std::fstream dataSementara;
    size = crud::getDataSize(data);

    std::cout << "Hapus nomor: ";
    std::cin >> nomor;

    crud::writeData(data, nomor, blankMahasiswa);

    dataSementara.open("temp.dat", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);

    offset = 0;
    for (int i = 1; i <= size; i++)
    {
        tempMahasiswa = crud::readData(data, i);

        if(tempMahasiswa.nama[0] != '\0')
        {
            crud::writeData(dataSementara, i - offset, tempMahasiswa);
        }
        else
        {
            offset++;
            std::cout << "delete item" << std::endl;
        }
    }

    size = crud::getDataSize(dataSementara);
    data.close();
    data.open("data.bin", std::ios::trunc | std::ios::out | std::ios::binary);
    data.close();
    data.open("data.bin", std::ios::out | std::ios::in | std::ios::binary);

    for(int i = 1; i <= size; i++)
    {
        tempMahasiswa = crud::readData(dataSementara, i);
        crud::writeData(data, i, tempMahasiswa);
    }


};

void crud::checkDatabase(std::fstream &data)
{
    data.open("data.bin", std::ios::out | std::ios::in | std::ios::binary);
    
    if (data.is_open())
    {
        std::cout << "[--database ditemukan--]" << std::endl;
    }
    else
    {
        std::cout << "database tidak ditemukan, buat databse baru" << std::endl;
        data.close();
        data.open("data.bin", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
    }
}

int crud::getOption()
{
    int input;
//    system("cls");
    std::cout << "\n===Program CRUD Data Mahasiswa===" << std::endl;
    std::cout << "=================================" << std::endl;
    
    std::cout << "1. Tambah data Mahasiswa" << std::endl;
    std::cout << "2. Tampilkan data Mahasiswa" << std::endl;
    std::cout << "3. Ubah data Mahasiswa" << std::endl;
    std::cout << "4. Hapus data Mahasiswa" << std::endl;
    std::cout << "5. Selesai" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "pilih [1-5]? : ";

    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return input;
}
