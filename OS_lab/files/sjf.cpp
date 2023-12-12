#include <bits/stdc++.h>
using namespace std;
int calculate(vector<vector<int>> &ref, int n)
{
    float turn_around_time = 0, weighted_turn_around_time = 0;
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        int min_burst_time = INT_MAX;
        int selected_process = -1;
        for (int j = 0; j < n; j++)
        {
            if (ref[j][0] <= current_time && ref[j][1] < min_burst_time)
            {
                min_burst_time = ref[j][1];
                selected_process = j;
            }
        }
        if (selected_process == -1)
        {
            current_time++;
            i--; // To re-check this time slot in the next iteration
        }
        else
        {
            current_time += ref[selected_process][1];
            turn_around_time += (current_time - ref[selected_process][0]);
            weighted_turn_around_time += ((current_time - ref[selected_process][0]) / ref[selected_process][1]);
            ref[selected_process][0] = INT_MAX; // Mark process as executed
        }
    }
    turn_around_time /= n;
    weighted_turn_around_time /= n;
    cout << "\nAverage turn around time of this schedule is " << turn_around_time << endl
         << "Average waiting turn around time of this schedule is " << weighted_turn_around_time << endl;
    return 0;
}
int main()
{
    int n;
    cout << "Enter no. of processes : ";
    cin >> n;
    vector<pair<int, int>> process;
    for (int i = 0; i < n; i++)
    {
        int arrival_time, burst_time;
        cout << "\nEnter arrival time of " << i + 1 << " process : ";
        cin >> arrival_time;

        cout << "Enter burst time of " << i + 1 << " process : ";
        cin >> burst_time;

        process.push_back(make_pair(arrival_time, burst_time));
    }
    vector<vector<int>> ref;
    for (auto &p : process)
    {
        ref.push_back({p.first, p.second});
    }
    cout << "\nProcess\t    Arrival Time    \tBurst Time";
    for (int i = 0; i < n; i++)
    {
        cout << "\nP[" << i + 1 << "]\t\t  " << ref[i][0] << "\t\t    " << ref[i][1];
    }
    calculate(ref, n);
    return 0;
}
