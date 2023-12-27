#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a, int h)
{
    double temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}
int main()
{
    double p = 13;
    double q = 11;
    double n = p * q;
    double phin = (p - 1) * (q - 1);
    double e = 2;
    while (e < phin)
    {
        if (gcd(e, phin) == 1)
            break;
        else
            e++;
    }
    double d1 = 1 / e;
    double d = fmod(d1, phin);
    double m = 35;
    cout << "initial message :" << m << endl;
    double c = pow(m, e);
    double decry = pow(c, d);
    c = fmod(c, n);
    cout << "encrypted message :" << c << endl;
    decry = fmod(decry, n);
    cout << "decrypted message :" << decry;
    return 0;
}