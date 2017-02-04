#include <iostream>

using namespace std;

int Fib(int x);

//This would best be served as a Linked List to dynamically allocate spots for memory efficiency, however 100 spots in an array is not that inefficient.
//However, for a 32-bit integer it could be calculated that after 47 iterations it's useless as the value wraps around.  I did this as a proof of concept in terms of speed.
//It takes less than a quarter of a second to perform 100 iterations with a stored array to return values.
int FibStore[100];

int main()
{
    int iterations = 0;
    cout << "Greetings!  How many cycle of Fibonacci's sequence are we going through today? (Max 99)" << endl;
    cin >> iterations;
    cout << endl;
    if (iterations > 99)
    {
        cout << "I said 99 max, you little devil!" << endl;
    } else
    {
        for (int i = 0; i <= iterations; i++)
        {
            int num = Fib(i);
            //Ternary operator used to differentiate between iterations.  The check is to ensure no comma is awkwardly placed after the last value.
            cout << num << ((i==iterations)? "" : ",");
        }
    }
    return 0;
}

int Fib(int x)
{
    //Ternary operator used to reduce number of if statements.
    int res = (x == 0) ? 0 : 1;

    //Fibonacci's sequence in it's most basic form.  Fn = Fn-1 + Fn-2
    if (FibStore[x] != 0)
    {
        res = FibStore[x];
    } else if (x >= 3)
    {
        res = Fib(x-1) + Fib(x-2);
        FibStore[x] = res;
    }

    return res;
}
