#include <iostream>
using namespace std;

int main(){

/*    for(int a = 0; a <= 10; a++) {
        if(a == 5) {
            break; 
        }
        cout << a << endl;
        a++;
    }
*/


int b = 0;
while(b <= 10) {
    b++;
    if(b == 5) {
        continue;
    }
    cout << b << endl;
}

    cout << "selesai" << endl;


    return 0;
}