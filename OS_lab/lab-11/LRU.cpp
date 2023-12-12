#include <bits/stdc++.h>
using namespace std;

void print(auto &x)
{
    for (auto y : x)
    {
        cout << y << " ";
    }
    cout << endl;
}

int main()
{
    int capacity;
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << "Enter capacity : " << endl;
    cin >> capacity;
    deque<int> q(capacity);

    int page_faults = 0;
    deque<int>::iterator itr;
    q.clear();
    
    for (int i : arr)
    {
        itr = find(q.begin(), q.end(), i);
        if (itr == q.end()) //when not in 'q'
        {
            ++page_faults;
            if (q.size() == capacity)
            {
                q.erase(q.begin());
                q.push_back(i);
            }
            else
            {
                q.push_back(i);
            }
        }
        else
        {
            q.erase(itr);
            q.push_back(i);
        }
        print(q);
    }
    cout << "Page faults are : " << page_faults << endl;
    cout << "Page hits are : " << n - page_faults << endl;
}

// 13 7 0 1 2 0 3 0 4 2 3 0 3 2
