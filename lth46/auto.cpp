#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<typename T, typename U>
auto max(T a,  U b){
    return (a > b) ? T(a) : U(b);
}


main()
{
    auto a = 15;
    auto b = "test";
    double c = 15.432;
    float d = 14.5f;
    auto e = max(d, a);


    cout << a << " tipe : " <<  typeid(a).name() << endl;
    cout << b << " tipe : " <<  typeid(b).name() << endl;
    cout << c << " tipe : " <<  typeid(c).name() << endl;
    cout << d << " tipe : " <<  typeid(d).name() << endl;
    cout << e << " tipe : " <<  typeid(e).name() << endl;

    return 0;
}