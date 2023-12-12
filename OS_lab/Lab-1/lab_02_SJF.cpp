// #include <bits/stdc++.h>
// using namespace std;


// int main()
// {
//     ifstream input;
//     input.open("input.txt");

//     ofstream output;
//     output.open("output2.txt");

//     if (!input || !output)
//     {
//         cout << "Error in opening file." << endl;
//         exit(0);
//     }

//     int numberOfTask;
//     input >> numberOfTask;

//     vector<pair<int, int>> busTime(numberOfTask);
//     int temp;
//     for (int i = 0; i < numberOfTask; i++)
//     {
//         input >> temp;
//         busTime[i] = make_pair(temp, i + 1);
//     }

//     sort(busTime.begin(), busTime.end());

//     long long time = 0;
//     float avg_turnArroundTime = 0, avg_watingTime = 0, avg_responcetime = 0;

//     for (int i = 0; i < numberOfTask; i++)
//     {
//         cout << "Turn arrounnd time for P" << busTime[i].second << " is: " << time + busTime[i].first << endl;
//         output << "Turn arrounnd time for P" << busTime[i].second << " is: " << time + busTime[i].first << endl;
//         avg_turnArroundTime += time + busTime[i].first;

//         cout << "Wating time is: " << time - 0 << endl;
//         output << "Wating time is: " << time - 0 << endl;
//         // avg_watingTime+= time-0;

//         cout << "Responce Time is: " << time - 0 << endl;
//         output << "Responce Time is: " << time - 0 << endl;
//         avg_responcetime = avg_watingTime += time - 0;

//         time += busTime[i].first;
//         cout << endl;
//         output << endl;
//     }

//     cout << endl;
//     cout << "Avg turn- arround time: " << avg_turnArroundTime / numberOfTask << endl;
//     output << "Avg turn- arround time: " << avg_turnArroundTime / numberOfTask << endl;

//     cout << "Avg waiting time: " << avg_watingTime / numberOfTask << endl;
//     output << "Avg waiting time: " << avg_watingTime / numberOfTask << endl;

//     cout << "Avg Responce time: " << avg_responcetime / numberOfTask << endl;
//     output << "Avg responce time: " << avg_responcetime / numberOfTask << endl;

//     input.close();
//     output.close();

//     // assumption: arrival time is same for all (i.e :0, non-primitive )

//     return 0;
// }

// pre-emptive
#include <iostream>
using namespace std;
int main()
{
    int a[10], b[10], x[10];
    int waiting[10], turnaround[10], completion[10];
    int i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;
    cout << "\nEnter the number of Processes: "; // input
    cin >> n;
    cout << "\nEnter arrival time of process: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "\nEnter burst time of process: "; // input
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (i = 0; i < n; i++)
        x[i] = b[i];
    b[9] = 9999;
    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)
                smallest = i;
        }
        b[smallest]--;
        if (b[smallest] == 0)
        {
            count++;
            end = time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout << "Process"
         << "\t"
         << "burst-time"
         << "\t"
         << "arrival-time"
         << "\t"
         << "waiting-time"
         << "\t"
         << "turnaround-time"
         << "\t"
         << "completion-time" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << "\t\t" << x[i] << "\t\t" << a[i] << "\t\t" << waiting[i] << "\t\t" << turnaround[i] << "\t\t" << completion[i] << endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout << "\n\nAverage waiting time =" << avg / n;
    cout << "  Average Turnaround time =" << tt / n << endl;
}
