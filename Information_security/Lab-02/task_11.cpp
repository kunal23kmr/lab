#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixMultiply(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2)
{
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            for (int k = 0; k < cols1; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

string hillCipherEncrypt(const string &plaintext, const vector<vector<int>> &key)
{
    int keySize = key.size();
    int textSize = plaintext.size();
    int blockSize = keySize;

    string paddedText = plaintext;
    while (paddedText.size() % blockSize != 0)
    {
        paddedText += 'X';
    }

    for (char &c : paddedText)
    {
        c = toupper(c);
    }

    vector<vector<int>> textMatrix(textSize / blockSize, vector<int>(blockSize));
    int idx = 0;
    for (int i = 0; i < textMatrix.size(); ++i)
    {
        for (int j = 0; j < blockSize; ++j)
        {
            textMatrix[i][j] = paddedText[idx++] - 'A';
        }
    }

    vector<vector<int>> encryptedMatrix = matrixMultiply(textMatrix, key);

    string ciphertext = "";
    for (int i = 0; i < encryptedMatrix.size(); ++i)
    {
        for (int j = 0; j < blockSize; ++j)
        {
            ciphertext += (encryptedMatrix[i][j] % 26) + 'A';
        }
    }

    return ciphertext;
}

int main()
{
    string plaintext, keyString, ciphertext;
    vector<vector<int>> key;

    cout << "Enter the plaintext: ";
    cin >> plaintext;

    cout << "Enter the key as a square matrix (e.g., 2x2 or 3x3): " << endl;
    int keySize;
    cin >> keySize;

    cout << "Enter the key matrix elements (in row-major order): " << endl;
    key.resize(keySize, vector<int>(keySize));
    for (int i = 0; i < keySize; ++i)
    {
        for (int j = 0; j < keySize; ++j)
        {
            cin >> key[i][j];
        }
    }

    int determinant = key[0][0];
    if (keySize == 2)
    {
        determinant = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    }
    else if (keySize == 3)
    {
        determinant = key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1]) -
                      key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) +
                      key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0]);
    }

    if (determinant == 0)
    {
        cout << "The key is not invertible (non-singular). Please choose another key." << endl;
        return 1;
    }

    ciphertext = hillCipherEncrypt(plaintext, key);

    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
