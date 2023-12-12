// non-preemitive
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int time = 0;
    int n;
    cout << "Enter number of processes: " << endl;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, s; // a->arrival time , s->service time
        cout << "Enter admission time of " << i + 1 << "th process: ";
        cin >> a;
        cout << "Enter service time: ";
        cin >> s;
        v.push_back({a, s, i + 1});
    }

    vector<bool> done(n, false);

    


    return 0;
}