#include <iostream>

#define PI 3.14159265359
#define BAHASA "Indonesia"
#define KUADRAT(X) (X*X)
#define MAX(A,B) ((A > B) ? A : B)


using namespace std;

main()
{
    
    cout << "nilai pi: " << PI << endl;
    cout << "Bahasa: " << BAHASA << endl;
    cout << "Kuadrat: " << KUADRAT(5) << endl;
    cout << "max: " << MAX(4,5) << endl;

    #undef BAHASA
    #define BAHASA "inggris"
    cout << "Bahasa: " << BAHASA << endl;

    return 0;
}