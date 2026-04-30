#include <iostream>
#include <string>

using namespace std;

main(){

    string input;
    string kata_rahasia("lmao");



    while(true){
        cout << "input password : ";
        cin >> input;
        
        if(input == kata_rahasia){
            cout << "=============================================================" << endl;
            cout << "Password benar!" << endl;
            break;
        } else { 
            cout << "Password salah coba lagi!" <<endl;

        }


    }

    cout << "selamat datang di perusahaan global ceo Xian Jing" << endl;
    cout << "=============================================================" << endl;


    return 0;
}