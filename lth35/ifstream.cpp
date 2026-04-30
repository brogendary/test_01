#include <iostream>
#include <fstream>
#include <string>
using namespace std;

main()
{
    ifstream myFile;
    string output, buffer;
    bool isData;
    int no;
    string nama;

    myFile.open("data.txt");
    
    while(!isData)
    {
        getline(myFile, buffer);
        output.append("\n" + buffer);
        if(buffer == "data")
        {
            isData = true;
        }
    }

    cout << output << endl;

    int jumlah_data = 0;
    getline(myFile, buffer);
    while(!myFile.eof())
    {
        myFile >> no;
        myFile >> nama;

        cout << no << "\t" << nama << endl;
        jumlah_data++;
    }

    cout << "jumlah data: " << jumlah_data << endl;

    return 0;
}