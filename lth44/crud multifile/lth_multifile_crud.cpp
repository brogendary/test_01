#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "crud.h"
//using namespace std;



// int getOption();
// void checkDatabase(fstream &data);
// void writeData(fstream &data, int posisi, Mahasiswa &inputMahasiswa);
// int getDataSize(fstream &data);
// Mahasiswa readData(fstream &data, int posisi);
// void addDataMahasiswa(fstream &data);
// void displayDataMahasiswa(fstream &data);
// void updateRecord(fstream &data);
// void deleteRecord(fstream &data);


int main()
{
    std::fstream data;
    crud::checkDatabase(data);
    
    
    int pilihan = crud::getOption();
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
            std::cout << "Menambah data Mahasiswa" << std::endl;
            crud::addDataMahasiswa(data);
            break;
            case READ:
            std::cout << "Tampilkan data Mahasiswa" << std::endl;
            crud::displayDataMahasiswa(data);
            break;
            case UPDATE:
            std::cout << "Ubah data Mahasiswa" << std::endl;
            crud::displayDataMahasiswa(data);
            crud::updateRecord(data);
            crud::displayDataMahasiswa(data);
            break;
            case DELETE:
            std::cout << "Hapus data Mahasiswa" << std::endl;
            crud::displayDataMahasiswa(data);
            crud::deleteRecord(data);
            crud::displayDataMahasiswa(data);
            break;
            default:
            std::cout << "Pilihan tidak ditemukan" << std::endl;
            break;
        }
            while(true)
            {
                std::cout << "Lanjutkan? [y/n] : ";
                std::cin >> is_continue;

                if(is_continue == 'y' || is_continue == 'Y')
                {
                    pilihan = crud::getOption();
                    break;
                }
                else if(is_continue == 'n' || is_continue == 'N')
                {
                    return 0;
                }
            }
        
        
    }
    
    std::cout << "akhir dari program" << std::endl;
    
    
    return 0;
}



