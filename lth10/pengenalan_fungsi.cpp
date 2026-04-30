#include <iostream>
#include <cmath>
using namespace std;

/* 
    menambahkaan library math (matematika)
    ceil(x) <- round up
    cos(x) <- cosine
    exp(x) <- exponent
    fabs(x) <- absolute value in float
    floor(x) <- round down
    fmod(x) <- modulus in float
    log(x) <- logarithm with natural base
    log10(x) <- logarithm with base 10
    pow(x,y) <- x raised to power y
    sin(x) <- sine
    sqrt(x) <- square root
    tan(x) <- tangent
*/

int main() {

    int x;
    cout << "akar dari nilai x = ";
    cin >> x;

    double y = sqrt(x);
    cout << "Akarnya = " << y << endl;



    return 0;
}