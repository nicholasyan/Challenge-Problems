#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int fibo(int n);

/* Print the nth number of Fibonacci sequence (recursively). 
 *
 * (Assume that 0 is the 1st number.)
 */

int main()
{
    int n;
    cin >> n;

    cout << fibo(n) << endl;

    return 0;
}

int fibo(int n)
{
    // start sequence with 0
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;

    return fibo(n - 2) + fibo(n - 1);
}
