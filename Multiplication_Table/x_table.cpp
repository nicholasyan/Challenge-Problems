#include <iostream>

using std::cout;
using std::endl;

#define LIMIT   13

/* Print a multiplication table for the numbers 0 through 12. */

int main()
{
    for (int y = 0; y < LIMIT; y++) {
        for (int x = 0; x < LIMIT; x++) {
            cout << x * y << "\t";
        }
        cout << endl;
    }
}