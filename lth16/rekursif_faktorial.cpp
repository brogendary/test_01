#include <iostream>
using namespace std;

int faktorial(int a){
    if (a <= 1){
        cout << a;
        return a;
    } else {
        cout << a << " * ";
        return a * faktorial(a - 1);
    }
        
    

}

int main(){
    int nilai;

    cout << "Input nilai faktorial = ";
    cin >> nilai;

    cout << "\nFaktorial " << nilai << "! = " << faktorial(nilai) << endl;

}