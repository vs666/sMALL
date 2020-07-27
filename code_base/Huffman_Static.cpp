#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class Node
{
public:
    char ch;
    Node *left, *right;
    long double p;
};
Node *head = NULL;
Node *makeNode()
{
    Node *ob = new Node();
    ob->p = 0;
    ob->left = ob->right = NULL;
    return ob;
}
void makeTree(priority_queue<pair<long double, Node *>, vector<pair<long double, Node *>>, greater<pair<long double, Node *>>> &prob)
{
    while (prob.size() > 1)
    {
        pair<long double, Node *> e1 = prob.top();
        prob.pop();
        pair<long double, Node *> e2 = prob.top();
        prob.pop();
        Node *com = makeNode();
        com->right = e1.second;
        com->left = e2.second;
        com->ch = '\0';
        com->p = e1.first + e2.first;
        prob.push({com->p, com});
    }
    head = prob.top().second;
}

void getCodes(map<char, string> &mp, string s, Node *n)
{
    if (n->left == NULL && n->right == NULL)
    {
        mp[n->ch] = s;
        return;
    }
    getCodes(mp, s + "0", n->left);
    getCodes(mp, s + "1", n->right);
}
vector<char> data;
vector<string> resultant;


/*
    Modulation of Code
    Contains bugs

*/
void compress(string &s)
{
    vector<long double> present(256, 0);
    for (auto x : s)
    {
        present[x]++;
    }
    priority_queue<pair<long double, Node *>, vector<pair<long double, Node *>>, greater<pair<long double, Node *>>> send;

    for (int x = 0; x < 256; x++)
    {
        present[x] = present[x] / s.length();
        if (present[x] != 0)
        {
            Node *a = makeNode();
            a->ch = x;
            a->p = present[x];
            send.push({a->p, a});
        }
    }
    makeTree(send);
    map<char, string> mp;
    getCodes(mp, "", head);
    int c = 7;
    unsigned char ip = 0;
    for (auto x : s)
    {
        for (auto y : mp[x])
        {
            if (c == -1)
            {
                c = 7;
                data.push_back(ip);
                ip = 0;
            }
            c--;
            if (y == '1')
            {
                ip = (ip | (1 << c));
            }
        }
    }
    // cout << "here" << endl;
    for (int x = 0; x < 256; x++)
    {
        if (mp[(char)x].length() == 0)
        {
            resultant.push_back("-");
        }
        else
            resultant.push_back(mp[(char)x] + "-");
    }
    // cout << "here too" << endl;
}

int main()
{
    string fn;
    ifstream ifo;
    // cout << "Enter filename to compress : ";
    cin >> fn;
    ifo.open(fn, ios::in);
    string s((std::istreambuf_iterator<char>(ifo)),
             (std::istreambuf_iterator<char>()));

    vector<long double> present(256, 0);
    for (auto x : s)
    {
        present[x]++;
    }
    priority_queue<pair<long double, Node *>, vector<pair<long double, Node *>>, greater<pair<long double, Node *>>> send;

    for (int x = 0; x < 256; x++)
    {
        present[x] = present[x] / s.length();
        if (present[x] != 0)
        {
            Node *a = makeNode();
            a->ch = x;
            a->p = present[x];
            send.push({a->p, a});
        }
    }
    makeTree(send);
    map<char, string> mp;
    getCodes(mp, "", head);
    int c = 7;
    char ip = 0;
    for (auto x : s)
    {
        for (auto y : mp[x])
        {
            if (c == -1)
            {
                c = 7;
                data.push_back(ip);
                ip = 0;
            }
            if (y == '1')
            {
                ip = (ip | (1 << c));
            }
            c--;
        }
    }
    if (c != 7)
    {
        data.push_back(ip);
    }
    for (int x = 0; x < 256; x++)
    {
        if (mp[(char)x].length() == 0)
        {
            resultant.push_back("-");
        }
        else
            resultant.push_back(mp[(char)x] + "-");
    }

    ofstream ofi;
    // cout << "Enter compressed filename (without Extension): ";
    cin >> fn;
    ofi.open(fn + "_metadata.txt", ios::out);
    for (auto x : resultant)
    {
        ofi << x;
    }
    ofi.close();
    ofi.open(fn + ".txt", ios::out);
    string s3 = "";
    int si = s.length();
    ofi << (unsigned char)(si&(0xFF000000));
    ofi << (unsigned char)(si&(0x00FF0000));
    ofi << (unsigned char)(si&(0x0000FF00));
    ofi << (unsigned char)(si&(0x000000FF));
    for (auto x : data)
    {
        ofi << x;
    }
    ofi.close();
    ifo.close();
    s.clear();
    // cout << "Done" << endl;
}
