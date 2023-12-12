#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number of Process:";
    cin >> n;
    queue<int> q1, q2, q3;
    int t1 = 4, t2 = 6;
    vector<pair<int, int>> arr;
    map<int, int> mp;
    double b = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
        mp[x] = i;
        b += y;
    }
    sort(arr.begin(), arr.end());
    int t = 0;
    while (mp.find(t) == mp.end())
        t++;
    q1.push(mp[t]);
    int i = t + 1;
    vector<int> tat(n);
    while (mp.size() > 0)
    {
        if (!q1.empty())
        {
            cout << "p" << q1.front() << " ";
            if (arr[q1.front()].second > t1)
            {
                arr[q1.front()].second -= t1;
                t += t1;
                q2.push(q1.front());
            }
            else
            {
                t += arr[q1.front()].second;
                tat[q1.front()] = (t - arr[q1.front()].first);
                mp.erase(arr[q1.front()].first);
            }
            q1.pop();
            while (i <= t)
            {
                if (mp.find(i) != mp.end())
                {
                    q1.push(mp[i]);
                }
                i++;
            }
        }
        else if (!q2.empty())
        {
            cout << "p" << q2.front() << " ";
            int temp = 0;
            while (temp < t2 && arr[q2.front()].second && q1.empty())
            {
                t += 1;
                arr[q2.front()].second -= 1;
                if (arr[q2.front()].second == 0)
                {
                    tat[q2.front()] = (t - arr[q2.front()].first);
                    mp.erase(arr[q2.front()].first);
                    q2.pop();
                    break;
                }
                if (mp.find(t) != mp.end())
                {
                    q1.push(mp[t]);
                    break;
                }
                temp += 1;
            }
            if (temp == t2)
            {
                q3.push(q2.front());
                q2.pop();
            }
        }
        else if (!q3.empty())
        {
            cout << "p" << q2.front() << " ";
            while (arr[q3.front()].second && q1.empty())
            {
                t++;
                arr[q3.front()].second -= 1;
                if (mp.find(t) != mp.end())
                {
                    q1.push(mp[t]);
                    break;
                }
                if (arr[q3.front()].second == 0)
                {
                    tat[q3.front()] = (t - arr[q3.front()].first);
                    mp.erase(arr[q3.front()].first);
                    q2.pop();
                    break;
                }
            }
        }
        else
        {
            t++;
        }
        i = t;
    }
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        s += tat[i];
    }
    cout << "\nAverage turnaround time:" << s / (n * 1.0) << "\n"
         << "Average waiting time:" << (s - b) / (n * 1.0);
    return 0;
}