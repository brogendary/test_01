#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Masukkan panjang n = ";
    cin >> n;

    cout << "Pola 1" << endl;

    for(int a = 0; a <= n; a++) {
        for(int b = 1; b <= a; b++){
            cout << "*";
        }
        cout << endl;
    }

    

    for(int a = 0; a <= n; a++) {
        for(int b = n; b >= a; b--){
            cout << "*";
        }
        cout << endl;
    }




    return 0;
}