#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    string inp_filename;
    cin >> inp_filename;

    ifstream infile;
    infile.open(inp_filename, ios::in);

    bool isfirst = true;
    char ch=0,chp=0;
    int freq = 0;
    while (infile >> noskipws >> ch)
    {
        // cout << (int)ch << endl;
        if(chp==0)
        {
            chp=ch;
        }
        else if(freq==0)
        {
            freq=(int)ch;
        }
        
        if(chp!=0 && freq!=0)
        {
            while (freq--)
            {
                cout << chp;
            }
            freq=0;
            chp=0;
        }
    }
    infile.close();
}