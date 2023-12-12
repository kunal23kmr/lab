#include <bits/stdc++.h>
using namespace std;

void print(auto &x)
{
    for (auto y : x)
    {
        cout << y << " ";
    }
    cout << endl;
}


void optimalPage(vector<int> &pg, int n, int fn)
{
    vector<int> fr(fn, -1);
    int hit = 0;
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < fn; j++)
        {
            if (fr[j] == pg[i])
            {
                hit++;
                found = true;
                break;
            }
        }
        if (found)
            continue;
        bool emptyFrame = false;
        for (int j = 0; j < fn; j++)
        {
            if (fr[j] == -1)
            {
                fr[j] = pg[i];
                emptyFrame = true;
                break;
            }
        }
        if (emptyFrame)
            continue;
        int farthest = -1, replaceIndex = -1;
        for (int j = 0; j < fn; j++)
        {
            int k;
            for (k = i + 1; k < n; k++)
            {
                if (fr[j] == pg[k])
                {
                    if (k > farthest)
                    {
                        farthest = k;
                        replaceIndex = j;
                    }
                    break;
                }
            }
            if (k == n)
            {
                replaceIndex = j;
                break;
            }
        }
        fr[replaceIndex] = pg[i];
    }
    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << n - hit << endl;
}

int main()
{

    vector<int> v;
    int n, capacity;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cout << "Enter capacity : " << endl;
    cin >> capacity;
    optimalPage(v, n, capacity);

    return 0;
}

// 14 1 2 3 4 5 6 7 8 9 1 2 3 4 5 4
