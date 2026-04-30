#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    char lanjut;
    while(true) {
        cout << "Lempar dadu? (y/n) " << endl;
        cin >> lanjut;
        if(lanjut == 'y') {
            cout << 1 + rand() % 6 << endl;
        } else if (lanjut == 'n') {
            break;
        } else {
            cout << "Input yang betul njing" << endl;
        }
        
        
    }


    return 0;
}