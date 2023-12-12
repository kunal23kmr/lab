#include <bits/stdc++.h>
using namespace std;

int n;

struct Process
{
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int finishing_time;
    int turn_around_time;
    bool done = false;
};
void solve(vector<Process> &process)
{
    queue<Process> q;
    double turn_around_time = 0, weighted_turn_around_time = 0;
    int current_time = 0;
}
int main()
{
    cout << "Enter number of process: ";
    cin >> n;

    vector<Process> process(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter process ID: ";
        cin >> process[i].id;
        cout << "Arrival time: ";
        cin >> process[i].arrival_time;
        cout << "Burst time: ";
        cin >> process[i].burst_time;
        cout << endl;
    }
    cout << "\nProcess\t    Arrival Time    \tBurst Time";
    for (int i = 0; i < n; i++)
    {
        cout << "\nP[" << i + 1 << "]\t\t  " << process[i].arrival_time << "\t\t    " << process[i].burst_time;
    }
    solve(process);
    return 0;
}