#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

/* Reverse a Given String */

int main()
{
    string word;
    char temp;
    int len, start, end;

    cin >> word;
    len = word.length();

    // length is 1-based indexed
    for (start = 0, end = len - 1; start < end; start++, end--) {

        temp = word[start];
        word[start] = word[end];
        word[end] = temp;

    }

    cout << word << endl;

    return 0;
}