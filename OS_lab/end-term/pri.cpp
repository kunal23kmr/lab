#include <bits/stdc++.h>
using namespace std;

int find_max(vector<int> arrival, vector<int> prio, int curr_time);

bool check(vector<int> &b)
{
    for (auto a : b)
    {
        if (a > 0)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> brust(n);
    vector<int> wait(n, 0);
    vector<int> arrival(n);
    vector<int> prio(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arrival[i] = a;
        brust[i] = b;
        cin >> prio[i];
    }

    int curr_time = *min_element(arrival.begin(), arrival.end());
    int ind = find_max(arrival, prio, curr_time);
    while (check(brust))
    {

        for (int i = 0; i < n; i++)
        {
            if (arrival[i] <= curr_time && i != ind)
            {
                wait[i]++;
            }
            if (wait[i] >= 5)
            {
                prio[i] = 0;
            }
        }
        brust[ind]--;
        if (brust[ind] == 0)
        {
            prio[ind] = 0;
        }
        cout<<ind<<" ";
        curr_time++;
        ind = find_max(arrival,prio,curr_time);
    }
    return 0;
}

int find_max(vector<int> arrival, vector<int> prio, int curr_time)
{
    for (int i = 0; i < arrival.size(); i++)
    {
        if (arrival[i] > curr_time)
        {
            prio[i] = 0;
        }
    }
    return find(prio.begin(), prio.end(), *max_element(prio.begin(), prio.end()))-prio.begin();
}

/*
arri, burst,prio

Test case:
2
0 6 1
1 4 5

*/