#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
ll power(ll a, ll b, ll n)
{
    ll result = 1;

    a = a % n; // Ensure 'a' is within the range [0, n-1]

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % n;
        }
        a = (a * a) % n;
        b /= 2;
    }

    return result;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}


pair<ll, ll> mul_inv(ll a, ll b)
{
    ll r1 = a;
    ll r2 = b;
    ll s1 = 1;
    ll s2 = 0;
    ll t1 = 0;
    ll t2 = 1;
    while (r2 > 0)
    {

        ll q = r1 / r2;
        ll r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        ll s = s1 - q * s2;
        s1 = s2;
        s2 = s;
        ll t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    if (t1 < 0)
    {
        t1 = (t1 + a) % a;
    }

    return {r1, t1};
}


int main()
{
    cout << endl;
    ll p = 823;
    ll q = 953;

    cout << "Value of 'P' (1st prime number) = " << p << endl;
    cout << "Value of 'Q' (2nd prime number) = " << q << endl;

    ll n = p * q;
    cout << "Value of 'N' is = " << n << endl;

    ll Pn = (p - 1) * (q - 1);

    ll key = 0;

    for (int i = 2; i < Pn; i++)
    {
        ll gcd_ = gcd(Pn, i);

        if (gcd_ == 1)
        {
            key = i;
            break;
        }
    }
    if (key == 0)
    {
        cout << "No premitive root of 'n' exist.";
        exit(0);
    }

    ll e = key;
    pair<ll, ll> inv = mul_inv(Pn, e);
    ll d;
    if (inv.first == 1)
    {
        d = inv.second;
        cout << "Decription key(d) is :" << d << endl;
    }
    else
    {
        cout << "No multiplicative inverse exist";
        exit(0);
    }

    cout << "\nPublic key:(N,e): (" << n << "," << e << ")" << endl;
    cout << "\nPrivate key:(N,d): (" << n << "," << d << ")" << endl;

    ll M; //  message to encrypt.
    cout << "Enter message: ";
    cin >> M;

    ll S = power(M, e, n); // signature by alice
    ll M1 = power(S, d, n); // decrypted msg by Bob.(reciver)

    if (M1 == M)
    {
        cout << "\n\nMessage accepted, accepted msg: " << M1 << endl;
    }
    else
    {
        cout << "There are some error in chanel, or signature" << endl;
    }

    cout << endl;

    return 0;
}

// 19070