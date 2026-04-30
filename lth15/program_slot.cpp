#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));


    double saldo, saldo_akhir;
    double harga_tiket = 10500;
    int jumlah_tiket, sisa_tiket;
    cout << "             *****Selamat Datang di Situs Nuzul 777*****" << endl;
    cout << "======================================================================" << endl;
    
    cout << "Mau depo berapa? = ";
    cin >> saldo;

    
    /*if(saldo - harga_tiket){
        sisa_tiket = saldo - (jumlah_tiket * tiket);
        } else if(){
            
        } else {
            cout << "Nominal anda kurang jelas" << endl;
            } */
           
           
           
           /*char lanjut;
           while(true) {
            cout << "Gass Depo!!! (y/n) " << endl;
            cin >> lanjut; */
    if (cin.fail()){
                cout << "yang serius bossku, ini bukan angka!!!" << endl;
    } else {
                
                cout << "Harga tiket = Rp 10.500" << endl;
                cout << "Mau beli tiket berapa = ";
                cin >> jumlah_tiket;
                 
                harga_tiket = jumlah_tiket * harga_tiket;
                saldo_akhir = saldo - harga_tiket;
                //jumlah_tiket = saldo_akhir / harga_tiket;
                cout << "======================================================================" << endl;
                cout << "Saldo anda tersisa = " << saldo_akhir << endl;
                cout << "======================================================================" << endl;



                if(saldo >= harga_tiket){
                for(int x = jumlah_tiket; x > 0 ; x--){
                
                //if(lanjut == 'y') {
                    
                     int a =  rand() % 9 + 1;
                     int b =  rand() % 9 + 1;
                     int c =  rand() % 9 + 1;
                     int d =  rand() % 9 + 1;
                     int e =  rand() % 9 + 1;
                     int f =  rand() % 9 + 1;
                     int g =  rand() % 9 + 1;
                     int h =  rand() % 9 + 1;
                     int i =  rand() % 9 + 1;
     
                     cout << " | " << a << " | ";
                     cout << " | " << b << " | ";
                     cout << " | " << c << " | " << endl;
     
                     cout << " | " << d << " | ";
                     cout << " | " << e << " | ";
                     cout << " | " << f << " | " << endl;
     
                     cout << " | " << g << " | ";
                     cout << " | " << h << " | ";
                     cout << " | " << i << " | " << endl;
     
                     if(a == b && b == c || d == e && e == f || g == h && h == i){
                         cout << "*********************************************************************" << endl;
                         cout << "$$$$$ GACORRR KINGGGG $$$$$" << endl;
                         cout << "KLONTONG KLONTONG KLONTONG" << endl;
                         cout << "*********************************************************************" << endl;
                     } else {
                         cout << "---------------------------------------------------------------------" << endl;
                         cout << "Jangan patah semangat, GASSS TERUSSSS REZEKI MENANTIMU!!!!" << endl;
                         cout << "INGATTTT, ada anak yang harus dibiayai" << endl;
                         cout << "---------------------------------------------------------------------" << endl;
                     }
     
     
                 /*} else if (lanjut == 'n') {
                     break;
                 } else {
                     cout << "Input yang betul njing" << endl;
                 }*/
             
                 
                                }
                            } else {
                            cout << "======================================================================" << endl;
                            cout << "saldo anda kurang boss, tambah lagi lagi biar GACORRRRR!!!!!" << endl;
                            cout << "======================================================================" << endl;
                            }
                            cout << "\n======================================================================" << endl;
                            cout << "Tiket mu habis Boss! \nsaran gw mending TOP UP lagi!!! \nGACORRR MENUNGGUMUUUU GASSS BOSSSKUUU!!!!!!" << endl;
                            cout << "======================================================================" << endl;
    }



    return 0;
}