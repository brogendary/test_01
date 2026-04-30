#include <iostream>
using namespace std;

int main() {

    //Bilangan bulat
    unsigned int a = 1; // 32bit
    long b = 2;
    short c = 3;

    //Bilangan decimal
    float d = 4.5;
    double e = 5.2;

    //character
    char f = 'a'; // character 1 bit

    //boolean
    bool g = true; // true/false

    cout << f << endl;
    cout << sizeof(c) << " Byte" << endl;
    //cout << numeric_limits<short>::max() << endl;
    //cout << numeric_limits<short>::min() << endl;
    


    return 0;
}