#include <bits/stdc++.h>
using namespace std;

int currentTime = 0;

class process
{
public:
    int at;
    int st;
    string name;
    bool done;
    float rr;
    int wt;
    process() {}
    process(int a, int b, string n)
    {
        at = a;
        st = b;
        name = n;
        done = false;
        wt = 0;
    }

    float responce()
    {
        rr = ((currentTime - at + st) / st);
        wt = currentTime - at;
    }
};

bool comp(const process &a, const process &b)
{
    return a.at < b.at;
}

void find_process(vector<process> &v, process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].at <= currentTime && !p[i].done)
        {
            p[i].responce();
            v.push_back(p[i]);
        }
    }
}
int main()
{
    process p[5] = {process(0, 3, "P1"), process(2, 3, "P2"), process(3, 5, "P3"), process(4, 2, "P4"), process(8, 3, "P5")};
    sort(p, p + 5, comp);

    for (int i = 0; i < 5; i++)
    {
        cout << p[i].name << " ";
    }
    int cnt = 0;
    while (cnt < 5)
    {
        vector<process> currentProcess;
        find_process(currentProcess, p, 5);
        process maxRR;
        
    }
    return 0;
}