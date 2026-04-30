#include <iostream>
#include <string>
using namespace std;

main(){

    string kalimat_1("lmao suka makan ayam kanji");
    string kalimat_2("lmoa orangnya suki bgt lmao");

    cout << "1: " << kalimat_1 << endl;
    cout<< "2 :" << kalimat_2 << endl;

    cout << kalimat_1.substr(5,4) << endl;
    cout << kalimat_2.substr(14,4) << endl;

    cout << kalimat_1.find("makan") << endl;
    cout << kalimat_2.find("orang") << endl;

    cout << kalimat_1.find("ka") << endl;

    int a = kalimat_1.find("ka");
    cout << kalimat_1.find("ka", a + 1) << endl;

    cout << kalimat_2.rfind("lm") << endl;

    return 0;
}