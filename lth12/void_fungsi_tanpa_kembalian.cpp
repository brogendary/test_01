#include <iostream>
using namespace std;

int kuadrat(int x){
    int y;
    
    y = x * x;

    return y;
}

void tampilkan(int input){
    cout << "make void ini" << endl;
    cout << input << endl;

}

int main(){
    int input, hasil;

    cout << "nilai kuadrat dari ";
    cin >> input;

    hasil = kuadrat(input);
    tampilkan(hasil);

    return 0;
}