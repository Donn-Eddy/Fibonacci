#include <iostream>

using namespace std;

int Fib(int x);

int main()
{
    int iterations = 0;
    cout << "Greetings!  How many cycle of Fibonacci's sequence are we going through today?" << endl;
    cin >> iterations;
    cout << endl;
    for (int i = 0; i <= iterations; i++)
    {
        int num = Fib(i);
        //Ternary operator used to differentiate between iterations.  The check is to ensure no comma is awkwardly placed after the last value.
        cout << num << ((i==iterations)? "" : ",");
    }
    return 0;
}

int Fib(int x)
{
    //Ternary operator used to reduce number of if statements.
    int res = (x == 0) ? 0 : 1;

    //Fibonacci's sequence in it's most basic form.  Fn = Fn-1 + Fn-2
    if (x >= 3)
    {
        res = Fib(x-1) + Fib(x-2);
    }

    return res;
}
