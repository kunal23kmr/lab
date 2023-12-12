// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ifstream input;
//     ofstream output;

//     input.open("input.txt");
//     output.open("output.txt");

//     if (!input || !output)
//     {
//         cout << "Error in opening file." << endl;
//         exit(0);
//     }

//     int numberOfTask;
//     input >> numberOfTask;

//     vector<int> busTime(numberOfTask);
//     for (int i = 0; i < numberOfTask; i++)
//     {
//         input >> busTime[i];
//     }

//     float avg_turnArroundTime = 0, avg_watingTime = 0, avg_responcetime = 0;

//     long long time = 0;

//     for (int i = 0; i < numberOfTask; i++)
//     {
//         cout << "Turn arrounnd time for P" << i + 1 << " is:" << time + busTime[i] << endl;
//         output << "Turn arrounnd time for P" << i + 1 << " is:" << time + busTime[i] << endl;
//         avg_turnArroundTime += time + busTime[i];

//         cout << "Wating time is: " << time - 0 << endl;
//         output << "Wating time is: " << time - 0 << endl;
//         // avg_watingTime += time-0;
    
//         cout << "Responce Time is: " << time - 0 << endl;
//         output << "Responce Time is: " << time - 0 << endl;
//         avg_responcetime = avg_watingTime += time-0;

//         time += busTime[i];
//         cout << endl;
//         output << endl;
//     }

//     cout<<endl;
//     cout<<"Avg turn- arround time: "<<avg_turnArroundTime/numberOfTask<<endl;
//     output<<"Avg turn- arround time: "<<avg_turnArroundTime/numberOfTask<<endl;

//     cout<<"Avg waiting time: "<<avg_watingTime/numberOfTask<<endl;
//     output<<"Avg waiting time: "<<avg_watingTime/numberOfTask<<endl;

//     cout<<"Avg Responce time: "<<avg_responcetime/numberOfTask<<endl;
//     output<<"Avg responce time: "<<avg_responcetime/numberOfTask<<endl;



//     input.close();
//     output.close();
    

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numberOfTask;
    cout<<"Input Number of Tasks.";
    cin >> numberOfTask;
    vector<int> busTime(numberOfTask);
    cout<<"Enter BustTime for each task.";
    for (int i = 0; i < numberOfTask; i++)
    {
        cin >> busTime[i];
    }
    float avg_turnArroundTime = 0, avg_watingTime = 0, avg_responcetime = 0;
    long long time = 0;
    for (int i = 0; i < numberOfTask; i++)
    {
        cout << "Turn arrounnd time for P" << i + 1 << " is:" << time + busTime[i] << endl;
        avg_turnArroundTime += time + busTime[i];
        cout << "Wating time is: " << time - 0 << endl;
        cout << "Responce Time is: " << time - 0 << endl;
        avg_responcetime = avg_watingTime += time-0;
        time += busTime[i];
    }
    cout<<"Avg turn- arround time: "<<avg_turnArroundTime/numberOfTask<<endl;
    cout<<"Avg waiting time: "<<avg_watingTime/numberOfTask<<endl;
    cout<<"Avg Responce time: "<<avg_responcetime/numberOfTask<<endl;
    return 0;
}
