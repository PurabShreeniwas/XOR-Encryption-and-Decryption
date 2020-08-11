#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    string filename, key;
    int key_length = 0;
    char c;
    ifstream fin;
    ofstream fout;
    cout << "Enter Filename: ";
    cin >> filename;
    fin.open(filename);
    if(!fin.is_open()){
        cout << "Error opening file!\n";
        return 1;
    }
    fout.open(filename + ".sec");
    cout << "Enter key: ";
    cin >> key;
    for(key_length = 0; key[key_length] != 0; ++key_length);

    for(int i = 0;;++i){
        fin.get(c);
        if(fin.eof())
            break;
        fout.put(c ^ ( key[i % key_length] ));
    }
    fin.close();
    fout.close();
    return 0;
}
