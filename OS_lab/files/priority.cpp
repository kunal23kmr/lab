#include <iostream>
using namespace std;
int main()
{
    int bt[20], p[20], wt[20], tat[20], pr[20], i, j, n, pos, temp;
    float total = 0, avg_wt, avg_tat, avg_wtat;
    cout << "Enter Total Number of Process : ";
    cin >> n;
    cout << "Enter Burst Time and Priority";
    for (i = 0; i < n; i++)
    {
        cout << "\nP[" << i + 1 << "]\n";
        cout << "Burst Time:";
        cin >> bt[i];
        cout << "Priority:";
        cin >> pr[i];
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;

        for (j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }
    avg_wt = total / n;
    total = 0;
    cout << "\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    int total1 = 0;
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        total1 += (tat[i] / bt[i]);
        cout << "\nP[" << p[i] << "]\t\t  " << bt[i] << "\t\t    " << wt[i] << "\t\t" << tat[i];
    }
    avg_tat = total / n;
    avg_wtat = total1 / n;
    cout << "\nAverage Turnaround Time=" << avg_tat;
    cout << "\nAverage Waited Turnaround Time=" << avg_wtat;
    return 0;
}