#include <iostream>
using namespace std;

int main() {

    int a = 1;
    int b = 2;
    bool hasil;

    //operator logika : not, and , or
    cout << "====Operator Logika==== \n";
    cout << "\n";

    //not
    cout << "NOT / ! \n";
    hasil = !(a == 1);
    cout << "not = " << hasil << endl;
    cout << "\n";

    //and
    cout << "AND / && \n";
    hasil = (a == 1) && (b == 2);
    cout << "and = " << hasil << endl;
    hasil = (a == 1) and (b != 2);
    cout << "and = " << hasil << endl;
    cout << "\n";

    //or
    cout << "OR / || \n";
    hasil = (a == 1) || (b == 2);
    cout << "or = " << hasil << endl;
    hasil = (a != 1) or (b == 2);
    cout << "or = " << hasil << endl;



    return 0;
}