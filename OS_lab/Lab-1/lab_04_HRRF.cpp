// // non-premitive
// #include <bits/stdc++.h>
// using namespace std;
// struct process
// {
//     char name;
//     float at, bt, ct, wt, tt;
//     int completed;
//     float ntt;
// } p[10];

// int n;

// double wtt(int i)
// {
//     double ans;
//     ans = 2 + (p[i].wt / p[i].bt);
//     return ans;
// }
// void sortByArrival()
// {
//     struct process temp;
//     int i, j;
//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = i + 1; j < n; j++)
//         {
//             if (p[i].at > p[j].at)
//             {
//                 temp = p[i];
//                 p[i] = p[j];
//                 p[j] = temp;
//             }
//         }
//     }
// }

// int main()
// {
//     int i, j, sum_bt = 0;
//     char c;
//     float t, avgwt = 0, avgtt = 0;
//     n = 5;
//     int arriv[] = {0, 2, 3, 4, 8};
//     int burst[] = {3, 3, 5, 2, 3};
//     for (i = 0, c = 'A'; i < n; i++, c++)
//     {
//         p[i].name = c;
//         p[i].at = arriv[i];
//         p[i].bt = burst[i];
//         p[i].completed = 0;
//         sum_bt += p[i].bt;
//     }
//     sortByArrival();
//     float weighted_turn = 0;
//     for (t = p[0].at; t < sum_bt;)
//     {
//         float hrr = -9999;
//         float temp;
//         int loc;
//         for (i = 0; i < n; i++)
//         {
//             if (p[i].at <= t && p[i].completed != 1)
//             {
//                 temp = (p[i].bt + (t - p[i].at)) / p[i].bt;
//                 if (hrr < temp)
//                 {
//                     hrr = temp;

//                     loc = i;
//                 }
//             }
//         }
//         t += p[loc].bt;
//         p[loc].wt = t - p[loc].at - p[loc].bt;
//         p[loc].tt = t - p[loc].at;
//         avgtt += p[loc].tt;
//         cout << avgtt << " ";
//         weighted_turn += ((p[loc].tt / p[loc].bt) + 1);

//         p[loc].ntt = ((float)p[loc].tt / p[loc].bt);
//         p[loc].completed = 1;
//         avgwt += p[loc].wt;
//     }
//     cout << "\nAverage Turn Around time: " << avgtt / 5;
//     cout << "\nWeighted turnarround time: " << weighted_turn / 5 << endl
//          << endl;
// }

#include <iostream>
struct process
{
    char name;
    int at, bt, ct, wt, tt;
    int complete;
    float ntt;
} p[10];

int m;

void sortByArrival()
{
    struct process temp;
    int i, j;

    // Selection Sort applied
    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {

            // This condition is used to Check for the lesser arrival time
            if (p[i].at > p[j].at)
            {

                // Swaping of earlier process to front
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main()
{
    int i, j, t, sum_bt = 0;
    char c;
    float avgwt = 0, avgtt = 0;
    m = 5;

    int arriv[] = {1, 3, 5, 7, 8};

    // the predefined burst times
    int burst[] = {3, 7, 8, 4, 2};

    // Initialize the structure variables
    for (i = 0, c = 'A'; i < m; i++, c++)
    {
        p[i].name = c;
        p[i].at = arriv[i];
        p[i].bt = burst[i];

        // Variable for Completion status
        // for Pending = 0
        // for Completed = 1
        p[i].complete = 0;

        // the Variable for the sum of all Burst Times
        sum_bt += p[i].bt;
    }

    // Let us Sort the structure by the arrival times
    sortByArrival();
    printf("\nName\tArrival Time\tBurst Time\tWaiting Time");
    printf("\tTurnAround Time\t Normalized TT");
    for (t = p[0].at; t < sum_bt;)
    {

        // Now Set the lower limit to response ratio
        float hrr = -9999;

        // The Response Ratio Variable
        float temp;

        // Variable used to store the next processs selected
        int loc;
        for (i = 0; i < m; i++)
        {
            // Check if the process has arrived and is Incomplete
            if (p[i].at <= t && p[i].complete != 1)
            {
                // Calculating the Response Ratio
                temp = (p[i].bt + (t - p[i].at)) / p[i].bt;
                // Checking for the Highest Response Ratio
                if (hrr < temp)
                {
                    // Storing the Response Ratio
                    hrr = temp;
                    // Storing the  Location
                    loc = i;
                }
            }
        }
        // Updating the time value
        t += p[loc].bt;
        // Calculation of the waiting time
        p[loc].wt = t - p[loc].at - p[loc].bt;
        // Calculation of the Turn Around Time
        p[loc].tt = t - p[loc].at;

        // Sum of Turn Around Time for the average
        avgtt += p[loc].tt;

        // Calculation of the Normalized Turn Around Time
        p[loc].ntt = ((float)p[loc].tt / p[loc].bt);
        p[loc].complete = 1;
        avgwt += p[loc].wt;
        printf("\n%c\t\t%d\t\t", p[loc].name, p[loc].at);
        printf("%d\t\t%d\t\t", p[loc].bt, p[loc].wt);
        printf("%d\t\t%f", p[loc].tt, p[loc].ntt);
    }
    printf("\nThe Average waiting time:%f\n", avgwt / m);
    printf("The Average Turn Around time:%f\n", avgtt / m);
}
