#include <iostream>

#define ID 1

#if ID == 1
    #define LANG "Indonesia"

#else
    #define lang "English"

#endif

using namespace std;

int main()
{
    
    cout << "Bahasa dipilih: " << LANG << endl;


    return 0;
}