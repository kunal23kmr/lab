#include <bits/stdc++.h>
using namespace std;
// searor
class encrypt
{
    string s;
    string es;
    int key;

public:
    encrypt()
    {
        cout << "Enter the string to encrypt :" << endl;
        cin >> s;
        cout << "Enter the key: ";
        cin >> key;
    }
    string fun()
    {
        key %= 26;
        es = "";
        for (int i = 0; i < s.size(); i++)
        {
            int c = (s[i] - 'a') % 26;
            es += 'a' + ((c + key) % 26);
        }
        return es;
    }
};
class decrypt
{
    string s;
    string ds;
    int key;

public:
    decrypt()
    {
        cout << "Enter the string to de-crypt:" << endl;
        cin >> s;
        cout << "Enter the key: ";
        cin >> key;
    }
    string fun()
    {
        key %= 26;
        ds = "";
        for (int i = 0; i < s.size(); i++)
        {
            int c = (s[i] - 'a') % 26;
            int a = ((c - key) % 26);
            ds += 'a' + (a >= 0 ? a : a + 26);
        }
        return ds;
    }
};

int main()
{
    cout << "\nChoose 1 for encrypt the messege and 2 for de-crypt." << endl;
    int a;
    cin >> a;
    if (a == 1)
    {
        encrypt obj;
        cout << "Encrypted messege is: " << obj.fun() << endl;
    }
    else if (a == 2)
    {
        decrypt obj;
        cout << "Decrypted messege is: " << obj.fun() << endl;
    }
    return 0;
}