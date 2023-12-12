#include <bits/stdc++.h>
using namespace std;
void print(set<int> &s)
{
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
}
int pageFaults(vector<int> &pages, int n, int capacity)
{
    set<int> s;
    queue<int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
        print(s);
    }
    cout << "Page faults are : " << page_faults << endl;
    cout << "Page Hits are : " << n - page_faults << endl;
    return page_faults;
}

int main()
{
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
        
    }
    // int capacity = 3;
    int cap = 0;
    cout << "Enter capacity: " << endl;
    cin >> cap;
    pageFaults(v, n, cap);
    return 0;
}

// 13 7 0 1 2 0 3 0 4 2 3 0 3 2