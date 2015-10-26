#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

/* Reverse a Given String (Recursively) */

string reverse_string(string word, int start, int end);

int main()
{
    string word, reversed;
    int len;

    cin >> word;
    len = word.length();

    // length is 1-based indexed
    reversed = reverse_string(word, 0, len - 1);

    cout << reversed << endl;

    return 0;
}

string reverse_string(string word, int start, int end)
{
    // base case
    if (end - start < 1)
        return word;

    else {

        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;

        return reverse_string(word, start + 1, end - 1);

    }

}

