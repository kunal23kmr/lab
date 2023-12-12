#include <bits/stdc++.h>
using namespace std;

const int PC1[] = {
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4};

const int SHIFTS[] = {
    1, 1, 2, 2, 2, 2, 2, 2,
    1, 2, 2, 2, 2, 2, 2, 1};

const int PC2[] = {
    14, 17, 11, 24, 1, 5, 3, 28,
    15, 6, 21, 10, 23, 19, 12, 4,
    26, 8, 16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55, 30, 40,
    51, 45, 33, 48, 44, 49, 39, 56,
    34, 53, 46, 42, 50, 36, 29, 32};

bitset<56> permutedChoice1(const bitset<64> &fullKey)
{
    bitset<56> permutedKey;
    for (int i = 0; i < 56; ++i)
    {
        permutedKey[i] = fullKey[PC1[i] - 1];
    }
    return permutedKey;
}

vector<bitset<48>> generateSubkeys(const bitset<64> &fullKey)
{
    vector<bitset<48>> subkeys;
    bitset<56> permutedKey = permutedChoice1(fullKey);

    bitset<28> leftKey = permutedKey >> 28;
    bitset<28> rightKey = permutedKey << 28;

    for (int i = 0; i < 16; ++i)
    {
        leftKey = (leftKey << SHIFTS[i]) | (leftKey >> (28 - SHIFTS[i]));
        rightKey = (rightKey << SHIFTS[i]) | (rightKey >> (28 - SHIFTS[i]));

        bitset<56> combinedKey = (leftKey.to_ullong() << 28) | rightKey.to_ullong();

        bitset<48> subkey;
        for (int j = 0; j < 48; ++j)
        {
            subkey[j] = combinedKey[PC2[j] - 1];
        }

        subkeys.push_back(subkey);
    }

    return subkeys;
}

int main()
{
    string keyInput;

    cout << "Enter 64-bit key: ";
    cin >> keyInput;

    bitset<64> fullKey(keyInput);

    vector<bitset<48>> subkeys = generateSubkeys(fullKey);

    for (int i = 0; i < 16; ++i)
    {
        cout << "Subkey " << i + 1 << ": " << subkeys[i] << endl;
    }

    return 0;
}
