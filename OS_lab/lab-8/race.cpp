#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main(void)
{
    int *count = new int;
    *count = 5;
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        perror("Fork error");
        exit(1);
    }
    else if (pid == 0)
    {
        (*count)++;
        cout << "value by child process" << *count << endl;
    }
    else
    {
        (*count)++;
        cout << "value by Parent process" << *count << endl;
    }
    // cout << "Final value in "<< ((pid==0)?"Child ":"Parent ") << (*count) << endl;
    exit(0);
}