#include <bits/stdc++.h>
using namespace std;
using ll = double;

int gcd(int a, int b)
{
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
bool isPrime(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime[n];
}
int main()
{
    int p = 10, q = 10;
    while (!isPrime(p))
    {
        cout << "Enter 'P' ";
        cin >> p;
    }
    while (!isPrime(q))
    {
        cout << "Enter 'Q' ";
        cin >> q;
    }

    cout << "\nThe value of 'P' and 'Q' is " << p << " " << q << endl;
    ll n = p * q;
    ll fn = (p - 1) * (q - 1);
    ll e;
    for (ll i = 2; i < fn; i++)
    {
        if (gcd(fn, i) == 1)
        {
            e = i;
            break;
        }
    }
    cout << e << endl;

    ll d = fmod(1 / e, fn);
    ll m;
    cout << "Enter initial message: ";
    cin >> m;
    ll c = pow(m, e);
    ll decrypt = pow(c, d);

    c = fmod(c, n);
    cout << "Encrypted Message:" << c << endl;

    decrypt = fmod(decrypt, n);
    cout << "decrypt message: " << decrypt << endl;
    return 0;
}