#include <iostream>

using namespace std;

enum warna
{
    merah, putih, hitam, coklat, kuning, biru
};


main()
{
    warna kain;
    kain = hitam;

    cout << kain << endl;

    if(kain == hitam)
    {
        cout << "kain warna hitam" << endl;
    }

    return 0;
}