#include <iostream>
using namespace std;

int main()
{
    // P0, P1, P2, P3 are the Process names here
    int n, m, i, j, k;
    n = 4;                         // Number of processes
    m = 3;                         // Number of resources
    int alloc[4][3] = {{1, 0, 1},  // P0 // Allocation Matrix
                       {1, 1, 2},  // P1
                       {1, 0, 3},  // P2
                       {2, 0, 0}}; // P3
    int max[4][3] = {{4, 3, 1},    // P0 // MAX Matrix
                     {2, 1, 4},    // P1
                     {1, 3, 3},    // P2
                     {5, 4, 1}};   // P3

    int avail[3] = {3, 3, 0}; // Available Resources

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    cout << "MAX NEED MATRIX:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << max[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nALLOCATION MATRIX:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << alloc[i][j] << " ";
        }
        cout << endl;
    }

    // Print Need Matrix
    cout << "\nCURRENT NEED MATRIX:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    // Print Available Resources
    cout << "\nMAXIMUM RESOUCES:" << endl;
    for (i = 0; i < m; i++)
    {
        cout << avail[i] << " ";
    }
    cout << endl;
    int flag = 1;

    // To check if sequence is safe or not
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            cout << "THE GIVEN SEQUENCE IS NOT SAFE !";
            break;
        }
    }

    if (flag == 1)
    {
        cout << "\nFOLLOWING IS THE SAFE SEQUENCE:" << endl;
        for (i = 0; i < n - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[n - 1] << endl;
    }

    return (0);
}
