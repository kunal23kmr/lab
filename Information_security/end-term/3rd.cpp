#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define endl '\n'

void RSA(int public_key, int n, int message);

int main()
{
    int n;
    string s;
    cin >> s;
    int p = 11, q = 13;
    n = q * p;
    int phi = (p - 1) * (q - 1);
    int e = 2;
    while (__gcd(e, phi) != 1)
    {
        e++;
    }
    if (e >= phi)
    {
        cout << "No 'e' value for n: " << n;
        return 0;
    }

    double d1 = 1 / e;
    double d = fmod(d, phi);

    cout << "Cipher text: " << endl;
    for (int i = 0; i < s.size(); i++)
    {
        RSA(d, n, (int)s[i]);
    }
    return 0;
}

void RSA(int public_key, int n, int message)
{
    int m = pow(message, public_key);
    m = m % n;
    cout << m;
}