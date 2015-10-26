#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

/* Reverse a Given String (Keeping Spaces in Their Original Positions)
 *
 * e.g. input:      I say hello world
 *      result:     d lro wolle hyasI
 *
 */

int main()
{
    string word;
    char temp;
    int len, start, end;

    getline(cin, word);
    len = word.length();

    // length is 1-based indexed
    for (start = 0, end = len - 1; start < end; start++, end--) {

        if (word[start] == ' ')
            start++;

        if (word[end] == ' ')
            end--; 

        // check that our initial condition still holds
        if (start < end) {
            temp = word[start];
            word[start] = word[end];
            word[end] = temp;
        }

    }

    cout << word << endl;

    return 0;
}