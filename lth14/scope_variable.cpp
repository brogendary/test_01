#include <iostream>
using namespace std;

int x = 10;

int var_global(){
    return x;
}

int var_x(){
    int x = 20;
    return x;
}


int main() {

    cout << "1. Variable Global " << x << endl;
    int x = 1000;
    cout << "2. Variable local main : " << x << endl;
    cout << "3. Variable var_global : " << var_global() << endl;
    cout << "4. Variable loca main : " << x << endl;
    cout << "5. Variable var_x : " << var_x << endl;
    cout << "6. Variable local main : " << x << endl;
    cout << "7. Variable local main : " << x << endl;
    {
    cout << "8. Variable local main : " << x << endl;
    int x = 30;
    cout << "9. Variable local block : " << x << endl;
    cout << "10. Variable var_global : " << var_global << endl;
    }
    cout << "11. Variable local main : " << x << endl;

    return 0;
}