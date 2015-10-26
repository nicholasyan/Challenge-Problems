#include <iostream>

using std::cout;
using std::endl;

/* Print the fist 10 numbers of the Fibonacci sequence (iteratively).
 *
 * 0 1 1 2 3 5 8 13 21 34
 *
 */

int main()
{
	// assume sequence starts with 0 and 1
	int num_one = 0;
	int num_two = 1;

	for (int count = 0; count < 10; count++) {

		std::cout << num_one << " ";

		double sum = num_one + num_two;
		num_one = num_two;
		num_two = sum;

	}

	std::cout << std::endl;

	return 0;
}
