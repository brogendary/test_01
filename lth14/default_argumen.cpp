#include <iostream>
using namespace std;

double volume_kubus(double a = 1, double b = 1, double c = 1);


int main(){

    cout << "Volume kubus : " << volume_kubus(3,4,5) << endl;
    cout << "Volume kubus : " << volume_kubus(3,4) << endl;
    cout << "Volume kubus : " << volume_kubus(3) << endl;
    cout << "Volume kubus : " << volume_kubus() << endl;


    return 0;
}

double volume_kubus(double a, double b, double c){
    return a * b * c;
}
