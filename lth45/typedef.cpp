#include <iostream>

using namespace std;

main()
{

    typedef int I;
    typedef int iVector2D[2];
    typedef unsigned long ulong;
    typedef double vector[2];

    using numbers = double;

    I a = 10;
    iVector2D b = {1,2};
    ulong c = 12087361;
    vector d = {10.980, 67.076};
    numbers e = 10.212312;

    cout << "nilai a : " << a << endl;
    cout << "isi dari array b : " << b[0] << " dan " << b[1] << endl;
    cout << "nilai c : " << c << endl;
    cout <<  "isi dari array d :" << d[0] << " dan " << d[1] << endl;
    cout << "nilai e : " << e << endl;


    return 0;
}