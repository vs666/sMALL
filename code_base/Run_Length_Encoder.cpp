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
    char ch, chp;
    int freq = 0;
    while (infile >> noskipws >> ch)
    {
        if (isfirst)
        {
            chp = ch;
            freq = 1;
            isfirst = false;
        }
        else if (ch == chp)
        {
            if (freq == 255)
            {
                cout << chp << (unsigned char)freq;
                // cout << chp << freq << ',';
                freq = 1;
            }
            else
            {
                freq++;
            }
        }
        else
        {
            cout << chp << (unsigned char)freq;
            freq=1;
            chp=ch;
        }
    }
    infile.close();
}