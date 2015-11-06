/*
 * ABBA.cpp
 *
 * Written By: Nicholas Yan
 *
 * Purpose: tests if a given string is in the format ABBA where A and B
 *          can be either characters or strings themselves
 * 
 *          catratratcat			YES ABBA
 *			catratcatrat			NOT ABBA
 * 
 */

#include <iostream>

using std::cout;
using std::cin;
using std::string;

bool check_ABBA(string word);

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	string word;

	cout << "Please enter a word:\n";
	cin >> word;

  	check_ABBA(word) ? cout << "ABBA form\n" : cout << "Not ABBA form\n";

	return 0;
}

bool check_ABBA(string word)
{
	int word_len = word.length();
	int substr_len = 0;	
	
	// ABBA must have an even number of characters	
	if (word_len % 2 != 0)
		return false;
	
	while (word_len != 0) {

		char seek = word[0];
		bool found_substr = false;

		while (!found_substr) {

				// ALGORITHM:
	
				// 1. Take the first character in the string; then search from the
				//    end of the string back forwards again until we find the
				//    character again
				// 2. Keep track of the characters we have to traverse from the
				//    back; this is the substring length
				
				while (substr_len < word_len / 2 && 
					   word[word_len - 1 - substr_len] != seek) {
					substr_len++;
				}

				// 3. Check if we exited the while loop because we didn't find a
				//    match
				if (substr_len >= word_len / 2)
					return false;
	
				// 4. Now assume we have found a valid substring. Using the
 			    //    substring length, check the substring at the beginning of
				//    the word to the one at the back, ensuring they are the
				//    same

				found_substr = true;
				
				for (int i = 0; i < substr_len; i++) {
	
					// if the substrings are not the same, keep expanding the
					// substring (perhaps we have encountered a word with
					// duplicate letters — e.g. cacoon)

					if (word[i] != word[word_len - 1 - substr_len + i])
						found_substr = false;
				}

				// 5. Regardless of whether we have found a valid substring or
				//    not, we want to increment:
				//
				//	  IF NOT FOUND		we want to continue the search
				//    IF FOUND			subtr_len is 0-based indexed so when
				//						we trim the word, we'll actually have
				//						to change it to 1-based indexed

				substr_len++;

		}	
		
		// chop-off the substrings and repeat the whole process on the remaining
		// part of the word
			
		word = word.substr(substr_len, word_len - 2 * substr_len);
		word_len = word.length();
		
		substr_len = 0;

	}
	
	return true;

}
