#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef double ll;

double po = 26;

void calcPo(ll size)
{
    po = log((double)1e18)/log(size);
}

ll makeHash(string &s)
{
    ll b = 1;
    ll ret = 0;
    for (int x = s.length() - 1; x >= 0; x--)
    {
        ret += ((double)s[x] / 256.0) * b;
        b *= po;
    }
    return ret;
}

int main()
{
    cout << "Enter String to transform" << endl;
    string s;
    getline(cin, s, '\n');
    // code for encoding
    string enc="";
    int findex;
    cin >> findex;

    // While processing string files...
    // unsigned int findex = ((unsigned int)s[0])<<24;
    // findex += ((unsigned int)s[1])<<16;
    // findex += ((unsigned int)s[2])<<8;
    // findex += ((unsigned int)s[3]);

    for(int x=0;x<s.length();x++)
    {
        enc+=s[x];
    }
    calcPo(enc.length());
    // code for decoding
    // findex is index...
    priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<pair<ll, string>>> pqnew;
    priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<pair<ll, string>>> pq;

    for (auto x : enc)
    {
        string ww2 = "";
        ww2 += x;
        pq.push({((ll)x/256.0), ww2});
    }
    for (int x = 1; x < enc.length(); x++)
    {
        pqnew = priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<pair<ll, string>>>();
        for (auto a : enc)
        {
            pqnew.push({pow(po, x) * ((double)a / 256.0) + pq.top().first, a + pq.top().second});
            pq.pop();
        }
        pq = pqnew;
    }
    int index = 0;
    string ans = "";
    cout << endl
         << endl;
    while (!pq.empty())
    {
        index++;
        if (index == findex)
            ans = pq.top().second;
        pq.pop();
    }
    cout << "Recovered string : ";
    cout << ans << endl;
}