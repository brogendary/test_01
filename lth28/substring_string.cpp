#include <iostream>
#include <string>
using namespace std;

main(){

    string kalimat_1("aku suka kamu suka, siapa? dia!");
    string kalimat_2("wakanda forevah!!!");

    cout << "1: " << kalimat_1 << endl;
    cout << "2: " << kalimat_2 << endl;

    kalimat_1.swap(kalimat_2);
    cout << "swap string" << endl;
    cout << "1: " << kalimat_1 << endl;
    cout << "2: " << kalimat_2 << endl;

    kalimat_2.replace(27, 3, "anjir");
    cout << "replace" << endl;
    kalimat_1.replace(kalimat_1.find("ah"), 2, "er");
    cout << "1: " << kalimat_1 << endl;
    cout << "2: " << kalimat_2 << endl;

    cout << "insert" << endl; 
    kalimat_1.insert(8, "dan hatiku ");
    cout << "1: " << kalimat_1 << endl;
    cout << "2: " << kalimat_2 << endl;

    return 0;
}