#include <cmath>
#include <iostream>

using namespace std;

long long int power(long long int a, long long int b, long long int P)
{
    if (b == 1)
    {
        return a;
    }
    return (((long long int)pow(a, b)) % P);
}

int main()
{
    long long int P, G, x, a, y, b, ka, kb;
    P = 23; // a prime number
    cout << "The value of P : " << P << endl;
    G = 9; // premitive root of P
    cout << "The value of G : " << G << endl;

    a = 2; // a choosen privet key for alice.
    cout << "The private key a for Alice : " << a << endl;

    x = power(G, a, P); // x= G^a mod P

    b = 3; // a choosen privet key for bob
    cout << "The private key b for Bob : " << b << endl;

    y = power(G, b, P); // y= G^b mod P

    // after key sharing
    ka = power(y, a, P); // secret key of alice, ka=y^a mod p
    kb = power(x, b, P); // secret key of bob,   kb = x^b mod P
    cout << "Secret key for the Alice is : " << ka << endl;

    cout << "Secret key for the Bob is : " << kb << endl;

    return 0;
}