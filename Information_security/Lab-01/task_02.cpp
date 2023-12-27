#include <bits/stdc++.h>
using namespace std;
string preprocessText(string text)
{
    string result;
    for (char ch : text)
    {
        if (isalpha(ch))
            result.push_back(toupper(ch));
    }
    return result;
}
vector<vector<char>> generateKeyTable(string key)
{
    vector<vector<char>> keyTable(5, vector<char>(5, ' '));
    vector<bool> used(26, false);
    int row = 0, col = 0;
    for (char ch : key)
    {
        if (ch == 'J')
            ch = 'I';
        if (isalpha(ch) && !used[ch - 'A'])
        {
            keyTable[row][col] = ch;
            used[ch - 'A'] = true;
            col++;
            if (col == 5)
            {
                col = 0;
                row++;
            }
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (ch == 'J')
            continue;
        if (!used[ch - 'A'])
        {
            keyTable[row][col] = ch;
            col++;
            if (col == 5)
            {
                col = 0;
                row++;
            }
        }
    }
    return keyTable;
}
pair<int, int> findPosition(const vector<vector<char>> &keyTable, char ch)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyTable[i][j] == ch)
                return {i, j};
        }
    }
    return {-1, -1};
}
string encryptPlayfair(const vector<vector<char>> &keyTable, string text)
{
    string ciphertext;
    for (size_t i = 1; i < text.length(); i += 2)
    {
        if (text[i] == text[i - 1])
            text.insert(i, "X");
    }
    if (text.length() % 2 != 0)
        text.push_back('X');
    for (size_t i = 0; i < text.length(); i += 2)
    {
        char ch1 = text[i];
        char ch2 = text[i + 1];
        if (ch1 == 'J')
        {
            ch1 = 'I';
        }
        if (ch2 == 'J')
        {
            ch2 = 'I';
        }
        int row1, col1, row2, col2;
        tie(row1, col1) = findPosition(keyTable, ch1);
        tie(row2, col2) = findPosition(keyTable, ch2);
        if (row1 == row2)
        {
            col1 = (col1 + 1) % 5;
            col2 = (col2 + 1) % 5;
        }
        else if (col1 == col2)
        {
            row1 = (row1 + 1) % 5;
            row2 = (row2 + 1) % 5;
        }
        else
        {
            swap(col1, col2);
        }
        ciphertext += keyTable[row1][col1];
        ciphertext += keyTable[row2][col2];
    }
    return ciphertext;
}
int main()
{
    string key, plaintext;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Enter the plaintext: ";
    cin >> plaintext;
    key = preprocessText(key);
    plaintext = preprocessText(plaintext);
    vector<vector<char>> keyTable = generateKeyTable(key);
    string ciphertext = encryptPlayfair(keyTable, plaintext);
    cout << "Ciphertext: " << ciphertext << endl;
    return 0;
}