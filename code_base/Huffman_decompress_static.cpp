#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    string file_metadata;
    // cout << "Enter the metadata file : ";
    // cout << "Enter filename of the metadata file : ";
    cin >> file_metadata;
    ifstream inp;
    inp.open(file_metadata, ios::in);
    string meta((std::istreambuf_iterator<char>(inp)),
                (std::istreambuf_iterator<char>()));
    map<string, unsigned char> mp;
    int index = 0;
    string val = "";
    for (auto x : meta)
    {
        if (x == '-')
        {
            if (val.size() != 0)
            {
                mp[val] = (unsigned char)index;
            }
            index++;
            val = "";
        }
        else
        {
            val += x;
        }
    }

    inp.close();
    string filename;
    // cout << "Enter the filename of the Compressed input file : ";
    cin >> filename;
    inp.open(filename, ios::in);
    unsigned char ch;
    string s2 = "";
    int count = 0;
    int si=0;
    for(int x=0;x<4;x++)
    {
        inp >> noskipws >> ch;
        si<<=8;
        si = ((int)(ch));
    }
    // cout << "Enter filename of decompressed file : ";
    string s44;
    cin >> s44;
    ofstream offile;
    offile.open(s44,ios::out);
    while (inp >> noskipws >> ch)
    {
        for (int x = 7; x >= 0; x--)
        {
            s2 = s2 + (char)('0' + ((ch >> x) & 1));
            if (s2.length() != 0 && mp[s2] != (unsigned char)0)
            {
                offile << mp[s2];
                s2 = "";
                count++;
            }
            if(count==si)
            {
                break;
            }
        }
    }
    inp.close();
}
