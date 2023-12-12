#include <bits/stdc++.h>
using namespace std;

string toupper(string s)
{
    for (auto &a : s)
    {
        a = toupper(a);
    }
    return s;
}

vector<vector<int>> matrixMultiply(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2)
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
int main()
{
    string palinText, key, cipher = "";
    cout << "Plain text:";
    cin >> palinText;
    cout << "Key :";
    cin >> key;

    palinText = toupper(palinText);
    key = toupper(key);

    int keysize = sqrt(key.size());
    cout << keysize << endl;
    vector<vector<int>> mat(keysize, vector<int>(keysize));
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            mat[i][j] = key[((i) * (keysize)) + j] - 'A';
        }
    }
    int height = (palinText.size() / keysize);
    if ((palinText.size() % keysize) > 0)
    {
        height++;
    }
    cout << height << endl;

    vector<vector<int>> text(height, vector<int>(keysize, 'Z'));
    for (int i = 0; i < palinText.size(); i++)
    {
        text[(i / (keysize))][(i % (keysize))] = (palinText[i] - 'A');
        // cout << text[(i / (keysize))][(i % (keysize))];
    }

    vector<vector<int>> encrypt = matrixMultiply(text, mat);

    for (int i = 0; i < encrypt.size(); i++)
    {
        for (int j = 0; j < encrypt[i].size(); j++)
        {
            cipher += ((encrypt[i][j] % 26) + 'A');
        }
    }
    cout << "Cipher is :" << cipher << endl;
    return 0;
}

// act
// gybnqkurp