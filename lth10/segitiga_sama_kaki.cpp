#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Masukkan panjang n = ";
    cin >> n;

   cout << "Pola 1" << endl;

    for(int a = 1; a <= n; a++) {
        for(int b = n;  b > a; b--){
            cout << " ";
        }

        for(int c = 1; c <= (2*a-1); c++) {
            cout << "*";
        }

        cout << endl;
    } 

    cout << "\nPola 2" << endl;
    for(int a = 1; a <= n; a++) {
        for(int b = 1; b < a; b++) {
            cout << " ";
        }

        for(int c = n; c >= (2*a - n); c--) {
            cout << "*";
        }


        cout << endl;
    }



    return 0;
}