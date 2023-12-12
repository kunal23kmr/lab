#include <bits\stdc++.h>
using namespace std;

struct Process
{
    int arrival_time;
    int burst_time;
    double response_ratio;
    bool done = false;
};

bool compareResponseRatio(const Process &p1, const Process &p2)
{
    return p1.response_ratio > p2.response_ratio;
}

int calculate(vector<Process> &processes, int n)
{
    double turn_around_time = 0, weighted_turn_around_time = 0;
    int current_time = 0;

    for (int i = 0; i < n; i++)
    {
        // Calculate response ratio for each process
        for (int j = 0; j < n; j++)
        {
            if (processes[j].done == false && processes[j].arrival_time <= current_time)
            {
                double waiting_time = current_time - processes[j].arrival_time;
                processes[j].response_ratio = (waiting_time + processes[j].burst_time) / processes[j].burst_time;
            }
            else
            {
                processes[j].response_ratio = 0; // Not yet arrived
            }
        }

        sort(processes.begin(), processes.end(), compareResponseRatio);

        current_time += processes[0].burst_time;
        turn_around_time += (current_time - processes[0].arrival_time);
        weighted_turn_around_time += ((current_time - processes[0].arrival_time) / processes[0].burst_time);
        processes[i].done = true;
    }

    turn_around_time /= n;
    weighted_turn_around_time /= n;
    cout << "\nAverage turn around time of this schedule is " << turn_around_time << std::endl
         << "Average waiting turn around time of this schedule is " << weighted_turn_around_time << std::endl;
    return 0;
}

int main()
{
    int n;
    cout << "Enter no. of processes : ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter arrival time of process " << i + 1 << " : ";
        cin >> processes[i].arrival_time;

        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> processes[i].burst_time;
    }
    cout << "\nProcess\t    Arrival Time    \tBurst Time";
    for (int i = 0; i < n; i++)
    {
        cout << "\nP[" << i + 1 << "]\t\t  " << processes[i].arrival_time << "\t\t    " << processes[i].burst_time;
    }
    calculate(processes, n);
    return 0;
}
