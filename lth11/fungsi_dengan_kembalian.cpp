#include <iostream>
using namespace std;

int kuadrat(int x){
    int y;
    
    y = x * x;

    return y;
}

int main(){
    int input, hasil;

    cout << "nilai kuadrat dari ";
    cin >> input;

    hasil = kuadrat(input);
    cout << hasil << endl;

    return 0;
}