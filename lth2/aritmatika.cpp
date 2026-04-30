#include <iostream>
using namespace std;

int main() {

    int a;
    int b;
    int hasil;

    cout << "=====ARITMATIKA=====" << "\n";
    cout << "note: hanya bilangan bulat!" << endl;
    cout << "\n";

    cout << "Input nilai pertama = ";
    cin >> a;
    cout << "Input nilai kedua = ";
    cin >> b;
    cout << "\n";

    //kabataku
    cout << "hasil" << "\n";

    hasil = a + b;
    cout << a << " + " << b << " = " << hasil << "\n";
    
    hasil = a - b;
    cout << a << " - " << b << " = " << hasil << "\n";

    hasil = a * b;
    cout << a << " * " << b << " = " << hasil << "\n";

    hasil = a / b;
    cout << a << " / " << b << " = " << hasil << "\n";

    hasil = a % b;
    cout << a << " % " << b << " = " << hasil << "\n";

    return 0;
}