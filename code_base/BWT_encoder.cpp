#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef double ll;

double po = 26;

void calcPo(ll size)
{
    po = log((double)1e18) / log(size);
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
    calcPo(s.length());
    ll hashnew = makeHash(s);
    unsigned int findex = -1;
    priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<pair<ll, string>>> pq;
    priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<pair<ll, string>>> pqnew;
    for (int x = 0; x < s.length(); x++)
    {
        string ns = "";
        for (int y = x; y < s.length() + x; y++)
        {
            ns += s[y % s.length()];
        }
        pq.push({makeHash(ns), ns});
    }
    string enc = "";
    pqnew = pq;
    // cout << pqnew.size() << endl;
    ll index = 1;
    while (!pqnew.empty())
    {
        enc += pqnew.top().second[pqnew.top().second.length() - 1];
        if (abs(hashnew - pqnew.top().first) <= 0.000001)
        {
            // cout << hashnew << endl;
            // cout << pqnew.top().first << endl;
            // cout << index << endl;
            findex = index;
        }
        index++;
        pqnew.pop();
    }
    cout << "Transormed string data : ";
    cout << enc << endl
         << findex << endl;
}
