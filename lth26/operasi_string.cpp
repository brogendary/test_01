#include <iostream>
#include <string>
using namespace std;

main(){

    string kata("cat");
    
    cout << kata << endl;

    cout << "" << kata[0] << endl;
    cout << "" << kata[1] << endl;
    cout << "" << kata[2] << endl;

    kata[1] = 'e';
    cout << kata << endl;

    string kata2(kata + "ar");
    cout << kata2 << endl;
    
    string kata3(" membahana");
    kata2.append(kata3);
    cout << kata3 << endl;

    string kata4("ahay!!!!!");
    kata2 += " " + kata4;
    cout <<  kata2 << endl;

    return 0;
}