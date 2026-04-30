#include <iostream>
#include "bersama.h"
#include "foo.h"
#include "bar.h"


#define LMAO "LMAO ada"

#ifdef LMAO   
#else
#define TEST_LMAO "LMAO tidak ada"
#endif

#ifndef LMAOO
#define LMAOO "membuat LMAO"
#endif

using namespace std;

int main()
{
    Mahasiswa mahasiswa;
    mahasiswa.NIM = 10;
   
    cout << LMAO << endl;
    cout << LMAOO << endl;

    cout << mahasiswa.NIM << endl;
    

    return 0;
}