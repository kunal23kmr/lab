#include <iostream>
#include <queue>
using namespace std;
struct Process
{
    int id;
    int burst_time;
};
int main()
{
    int n;
    int time_quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> time_quantum;
    queue<Process> ready_queue;
    vector<Process> processes;
    for (int i = 0; i < n; ++i)
    {
        int burst_time;
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> burst_time;
        processes.push_back({i + 1, burst_time});
    }
    int current_time = 0;
    while (!processes.empty())
    {
        Process current_process = processes.front();
        processes.erase(processes.begin());
        if (current_process.burst_time <= time_quantum)
        {
            current_time += current_process.burst_time;
            cout << "Process " << current_process.id << " completed at time " << current_time << endl;
        }
        else
        {
            current_time += time_quantum;
            current_process.burst_time -= time_quantum;
            cout << "Process " << current_process.id << " executed for time quantum and moved to the end of the queue at time " << current_time << endl;
            processes.push_back(current_process);
        }
    }
    return 0;
}