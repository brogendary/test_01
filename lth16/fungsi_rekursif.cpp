#include <iostream>
using namespace std;

int pangkatIterasi(int a, int b){
    int hasil = a;
    for(int i = 1; i < b; i++){
        hasil = hasil * a;
    }
    return hasil;
}

int pangkatRekursif(int a, int b){
    if(b <= 1){
        cout << "akhir dari rekursif" << endl;
        return a;
    }else{
        cout << "akhir dari rekursif" << endl;
        return a * pangkatRekursif(a,(b-1));
    }

}


int main(){
    int a, b;
    
    cout << "Nilai = ";
    cin >> a;
    cout << "Pangkat = ";
    cin >> b;

    cout << "Hasil iterasi = " << pangkatIterasi(a, b) << endl;
    cout << "Hasil rekursif = " << pangkatRekursif(a, b) << endl;

    return 0;
}