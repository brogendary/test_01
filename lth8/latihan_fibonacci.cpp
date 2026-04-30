#include <iostream>
using namespace std;

int main() {

    int n, f_n, f_n1, f_n2;

    cout << "Program Fibonacci" << endl;
    cout << "Input nilai n = ";
    cin >> n;

    f_n1 = 1;
    f_n2 = 0;
    f_n = f_n1 + f_n2;
    cout << f_n << " ";
    for(int a = 1; a <= n; a++) {
        f_n = f_n1 + f_n2;
        f_n2 = f_n1;
        f_n1 = f_n;
        cout << f_n << " ";
    }
    cout << "\n";


    return 0;
}