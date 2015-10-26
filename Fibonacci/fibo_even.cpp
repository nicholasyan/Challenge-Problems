#include <iostream>

/* Print the sum of the even numbers in the first 4 million terms of the Fibonacci sequence.
 *
 * 4613732
 *
 */

int main()
{
    int num_one = 1;
    int num_two = 2;

    int even_sum = 0;

    while(num_one < 4000000) {
    
        if(num_two % 2 == 0)
            even_sum += num_two;

        double sum = num_one + num_two;
        num_one = num_two;
        num_two = sum;
    }

    std::cout << even_sum << std::endl;

    return 0;
}
