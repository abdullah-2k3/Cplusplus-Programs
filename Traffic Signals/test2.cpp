#include <cstdio>
#include <signal.h>
#include <iostream>
#include <string>
#include "queue.cpp"
using namespace std;

int testno;
int totpoints;
int lastpoints;
int lasttotpoints;
int points;
int zero = 0;

void test_queue()
{
    lasttotpoints = 10;

    Queue<int> q;
    cout << ".";

    for (int i = 0; i < 25000; i++)
    {
        q.enqueue(i);
    }
    cout << ".";
    lastpoints += 3;

    Queue<int> q2(q);
    cout << ".";

    for (int i = 0; i < 25000; i++)
    {
        int k = q.front();
        int k2 = q.dequeue();

        if (k != k2 || k2 != i)
            int a = 1/zero;
    }
    cout << ".";
    lastpoints += 3;

    for (int i = 0; i < 25000; i++)
    {
        int k = q2.front();
        int k2 = q2.dequeue();

        if (k != k2 || k2 != i)
            int a = 1/ zero;
    }
    cout << ".";
    lastpoints += 4;
}

// Test case dispatcher
void dispatcher()
{
    while (true)
    {
        lastpoints = 0;
        lasttotpoints = 0;
        switch (testno)
        {
            case 0:
                {
                    cout << "Testing Queue ";
                    test_queue();
                }
                break;
            default:
                {
                    cout << "Total Points: " << points << " / " << totpoints << endl;
                    exit(0);
                }
        }
        cout << " Passed! " << lastpoints << " / " << lasttotpoints << endl;
        testno++;
        points += lastpoints;
        totpoints += lasttotpoints;
    }
}

// Signal handler for exceptions
void signal_handler(int signum)
{
    cout << " Failed! " << lastpoints << " / " << lasttotpoints << endl;

    testno++;
    points += lastpoints;
    totpoints += lasttotpoints;

    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);
    dispatcher();
}

//int main()
//{
//    // Set signal handlers
//    signal(SIGSEGV, signal_handler);
//    signal(SIGFPE, signal_handler);
//
//    cout << "Starting Tests" << endl;
//
//    testno = 0;
//    points = 0;
//    totpoints = 0;
//    dispatcher();
//
//}
