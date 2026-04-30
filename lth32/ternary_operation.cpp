#include <iostream>
#include <string>
using namespace std;


main()
{
    int a,b;
    string hasil1, hasil2, output;

    hasil1 = "lmao";
    hasil2 = "Bayu";

    a = 5;
    
    cout << "input nilai : ";
    cin >> b;

    output = (a < b) ? hasil1 : hasil2;
    cout << output << endl;



    return 0;
}