#include <bits/stdc++.h>
using namespace std;

string process_pt(string pt)
{
    string r;
    for (int i = 0; i < pt.size() - 1; i++)
    {
        if (pt[i] == pt[i + 1])
        {
            r.push_back(pt[i]);
            r.push_back(pt[i + 1]);
        }
        else
        {
            r.push_back(pt[i]);
        }
    }
    if (pt.back() == pt[pt.size() - 2])
    {
        r.push_back(pt.back());
    }
    if (r.size() % 2 != 0)
    {
        r.push_back('X');
    }
    return r;
}
pair<int, int> find(char c, vector<vector<char>> &mat)
{
    if (c == 'J')
    {
        c = 'I';
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mat[i][j] == c)
            {
                return {i, j};
            }
        }
    }
    return {0, 0};
}
int main()
{
    string key, pt;
    cout << "Enter the key: ";
    cin >> key;
    cout<<"Enter the plaintext";
    cin >> pt;

    vector<vector<char>> mat(5, vector<char>(5, ' '));
    vector<bool> visited(26, false);
    int a = 0, b = 0;
    for (int i = 0; i < key.size(); i++)
    {
        char c = key[i];
        if (c == 'J')
        {
            c = 'I';
        }
        if (!visited[c - 'A'])
        {
            visited[c - 'A'] = true;
            mat[a][b] = c;
            b++;
            if (b == 5)
            {
                b = 0;
                a++;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (visited[i] == false && i != ('J' - 'A'))
        {
            mat[a][b] = 'A' + i;
            b++;
            if (b == 5)
            {
                b = 0;
                a++;
            }
        }
    }

    pt = process_pt(pt);

    for (int i = 0; i < pt.size(); i += 2)
    {
        int x1, y1, x2, y2;
        tie(x1, y1) = find(pt[i], mat);
        tie(x2, y2) = find(pt[i + 1], mat);

        if (x1 == x2)
        {
            cout << mat[x1][(y1 + 1) % 5] << mat[x2][(y2 + 1) % 5];
        }
        else if (y1 == y2)
        {
            cout << mat[(x1 + 1) % 5][y1] << mat[(x2 + 1) % 5][y2];
        }
        else
        {
            cout << mat[x2][y1] << mat[x1][y2];
        }
    }

    return 0;
}