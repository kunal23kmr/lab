#include <bits/stdc++.h>
using namespace std;
struct Process
{
    int id;
    int burstTime;
    int priority;
};
class MFQ
{
private:
    vector<queue<Process>> queues;
    int num_q;
    int time_slice;

public:
    MFQ(int nq , int ts)
    {
        num_q = nq;
        queues.resize(nq);
        time_slice = ts;
    }
    void enqueue(Process process)
    {
        int iQue = process.priority;

        if (iQue < 0 || iQue >= num_q)
        {
            cout << "Invalid priority level." << endl;
            return;
        }

        queues[iQue].push(process);
    }
    void run()
    {

        cout << "Runnig from higher priority Queue:(Round Robbin):" << endl;
        for (int currQ = num_q - 1; currQ > 0; currQ--)
        {
            while (!queues[currQ].empty())
            {
                Process curr = queues[currQ].front();
                queues[currQ].pop();
                cout << curr.id << " ";
                if (curr.burstTime > 0)
                {
                    curr.priority--;
                    curr.burstTime -= time_slice;
                    if (curr.burstTime > 0)
                    {
                        curr.priority = min(0, curr.priority);
                        enqueue(curr);
                    }
                }
            }
        }
        cout << "\nRunnig remaning form Queue 1 in FCFS (Gantt Chart): " << endl;
        for (int i = 0; i < queues[0].size(); i++)
        {
            Process curr = queues[0].front();
            queues[0].pop();
            int s = curr.burstTime;
            while (s--)
            {
                cout << curr.id << " ";
            }
        }
    }
};
int main()
{
    int n;
    cout << "Enter number of queue: ";
    cin >> n;
    MFQ scheduler(n, 1);
    cout << "Enter number of Process: ";
    cin >> n;
    cout << "\nEnter Burst Time and Priority of Process: \n";
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "P" << i + 1 << ": ";
        cin >> a >> b;
        scheduler.enqueue({i + 1, a, b});
    }
    scheduler.run();
    return 0;
}