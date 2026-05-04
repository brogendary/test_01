#include <iostream>
#include <string>
#include <fstream>
#include <limits>

namespace crud
{

    struct Mahasiswa
    {
        int pk;
        char NIM[20];
        char nama[50];
        char jurusan[50];
    };

    void writeData(std::fstream &data, int posisi, Mahasiswa &inputMahasiswa)
    {
        data.seekp((posisi - 1) * sizeof(Mahasiswa), std::ios::beg);
        data.write(reinterpret_cast<char *>(&inputMahasiswa), sizeof(Mahasiswa));
    };

    int getDataSize(std::fstream &data)
    {
        int start, end;
        data.seekg(0, std::ios::beg);
        start = data.tellg();
        data.seekg(0, std::ios::end);
        end = data.tellg();
        return (end - start) / sizeof(Mahasiswa);
    };

    Mahasiswa readData(std::fstream &data, int posisi)
    {
        Mahasiswa readMahasiswa;
        data.seekg((posisi - 1) * sizeof(Mahasiswa), std::ios::beg);
        data.read(reinterpret_cast<char *>(&readMahasiswa), sizeof(Mahasiswa));
        return readMahasiswa;
    }

    void addDataMahasiswa(std::fstream &data)
    {
        Mahasiswa inputMahasiswa, lastMahasiswa;

        int size = getDataSize(data);
        std::cout << "ukuran data: " << size << std::endl;

        if (size == 0)
        {
            inputMahasiswa.pk = 1;
        }
        else
        {
            lastMahasiswa = readData(data, size);
            std::cout << "pk =" << lastMahasiswa.pk << std::endl;
            inputMahasiswa.pk = lastMahasiswa.pk + 1;
        }

        // readData(data, size);

        inputMahasiswa.pk = 1;
        std::cout << "Nama: ";
        std::cin.getline(inputMahasiswa.nama, 50);
        std::cout << "Jurusan: ";
        std::cin.getline(inputMahasiswa.jurusan, 50);
        std::cout << "NIM: ";
        std::cin.getline(inputMahasiswa.NIM, 20);

        writeData(data, size + 1, inputMahasiswa);
    };

    void displayDataMahasiswa(std::fstream &data)
    {
        int size = getDataSize(data);
        Mahasiswa showMahasiswa;
        std::cout << "no.\tpk.\tNIM.\tNama.\tJurusan." << std::endl;
        for (int i = 1; i <= size; i++)
        {
            showMahasiswa = readData(data, i);
            std::cout << i << "\t";
            std::cout << showMahasiswa.pk << "\t";
            std::cout << showMahasiswa.NIM << "\t";
            std::cout << showMahasiswa.nama << "\t";
            std::cout << showMahasiswa.jurusan << std::endl;
        }
    };

    void updateRecord(std::fstream &data)
    {
        int nomor;
        Mahasiswa updateMahasiswa;
        std::cout << "pilih nomor: ";
        std::cin >> nomor;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        updateMahasiswa = readData(data, nomor);
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

        writeData(data, nomor, updateMahasiswa);
    };

    void deleteRecord(std::fstream &data)
    {
        int nomor, size, offset;
        Mahasiswa blankMahasiswa, tempMahasiswa;
        std::fstream dataSementara;
        size = getDataSize(data);

        std::cout << "Hapus nomor: ";
        std::cin >> nomor;

        writeData(data, nomor, blankMahasiswa);

        dataSementara.open("temp.dat", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);

        offset = 0;
        for (int i = 1; i <= size; i++)
        {
            tempMahasiswa = readData(data, i);

            if (tempMahasiswa.nama[0] != '\0')
            {
                writeData(dataSementara, i - offset, tempMahasiswa);
            }
            else
            {
                offset++;
                std::cout << "delete item" << std::endl;
            }
        }

        size = getDataSize(dataSementara);
        data.close();
        data.open("data.bin", std::ios::trunc | std::ios::out | std::ios::binary);
        data.close();
        data.open("data.bin", std::ios::out | std::ios::in | std::ios::binary);

        for (int i = 1; i <= size; i++)
        {
            tempMahasiswa = readData(dataSementara, i);
            writeData(data, i, tempMahasiswa);
        }
    };

    void checkDatabase(std::fstream &data)
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

    int getOption()
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return input;
    }

}
