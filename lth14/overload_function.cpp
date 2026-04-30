#include <iostream>
using namespace std;

double luas(double p, double l);
double luas(double l);


int main(){

    cout << "Luas 2x2 = " << luas(2,3) << endl;
    cout << "Luas 2 = " << luas(2.7) << endl;

    return 0;
}

double luas(double p, double l){
    double luas;
    luas = p * l;
    return luas;
}

double luas(double l){
    double luas;
    luas = l * l;
    return luas;
}