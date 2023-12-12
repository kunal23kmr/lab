#include <bits/stdc++.h>
using namespace std;
// least completed next.
int main()
{
    int n;
    cout << "Enter no of processess: ";
    cin >> n;
    vector<pair<double, double>> v(n);
    double tat1 = 0;
    double tat = 0;
    int tot_bur = 0;
    cout << "Enter arrival and burst time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "process " << i + 1 << ": ";
        cin >> v[i].first >> v[i].second;
        tot_bur += v[i].second;
    }
    bool vis[n] = {false};
    int x;
    int s[n] = {0};
    cout << "Gantt chart acc to FCFS of LCN Scheduling: " << endl;
    for (int i = 0; i < tot_bur; i++)
    {
        int min = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (v[j].first <= i)
            {
                if (min > s[j] && vis[j] == false)
                {
                    min = s[j];
                    x = j;
                }
            }
        }
        cout << x + 1 << " ";
        s[x]++;
        if (v[x].second == s[x] && vis[x] == false)
        {
            vis[x] = true;
            tat += i + 1 - v[x].first;
            tat1 += (i + 1 - v[x].first) / v[x].second;
        }
    }
    cout << "\navg turnaround time: " << tat / n << endl;
    cout << "avg waited-turnaround time: " << tat1 / n << endl;
    return 0;
}