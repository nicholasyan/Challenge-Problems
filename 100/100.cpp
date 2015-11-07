#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using std::cout;
using std::vector;
using std::stoi;

void initialize_digits(int n, vector<int> &digits);
void initialize_signs(int n, vector<vector<char> > &sign_combos);
void evaluate_combos(vector<int> &digits, vector<vector<char> > &sign_combos, int sum);

int main(int argc, char **argv)
{
    if (argc != 3) {
        cout << "Usage: ./100 [num_digits] [sum]\n";
        exit(1);
    } 

    int num_digits = stoi(argv[1]);
    int sum = stoi(argv[2]);

    vector<int>	digits;
    vector<vector<char> > sign_combos;
   
    // load a vector with the digits 1, 2, ... , num_digits - 1
    initialize_digits(num_digits, digits);

    // generate all possible combinations of signs (+, -, or no sign)
    // that can fit between the digits
    initialize_signs(num_digits - 1, sign_combos);

    // evaluate each combination to see which combos create the desired sum
    evaluate_combos(digits, sign_combos, sum);

    return 0;
}

// loads a given vector with the digits 1, 2, ... , n - 1
void initialize_digits(int n, vector<int> &digits)
{
    for (int i = 1; i < n; i++) {
        digits.push_back(i);        
    }
 
}

// produces all possibilities of a vector with n slots where each slot can either
// have the value '+', '-', or 'c' (combine) 
void initialize_signs(int n, vector<vector<char> > &sign_combos)
{

    // BASE CASE: we have one slot; it can have three values
    if (n == 1) {
        
        vector<char> new_list;

        new_list.push_back('+');
        sign_combos.push_back(new_list);

        new_list[0] = '-';
        sign_combos.push_back(new_list);

        new_list[0] = 'c';
        sign_combos.push_back(new_list);

    } else {

        // ALGORITHM: Each '+', '-', and 'c' will be appended to all of the previous
        //            n - 1 possibilities

        // 1. Generate the set of n - 1 possibilties 3 times
        for (int i = 0; i < 3; i++) {
            initialize_signs(n - 1, sign_combos);
        }

        // 2. Append '+', '-', and 'c' to each of the sets

        int end = sign_combos.size();
        int num_lists = pow(3, n);

        // we need to do end - num_lists and not just start from 0 in case we are in
        // a recursive call (we won't always be modifying the 0th item in sign_cmobos)
        for (int i = end - num_lists, j = 0; j < num_lists / 3; i++, j++) {
            sign_combos[i].push_back('+');
            sign_combos[i + num_lists / 3].push_back('-');
            sign_combos[i + 2 * (num_lists / 3)].push_back('c');
        } 
       
    }
         
}

// finds all of the sign combinations that produce the desired sum amongst the given digit
void evaluate_combos(vector<int> &digits, vector<vector<char> > &sign_combos, int sum)
{
    int num_digits = digits.size();
    int num_sign_combos = sign_combos.size();

    vector<int> condensed_num;

    // for each sign combination ...
    for (int i = 0; i < num_sign_combos; i++) {
        
        // create a condensed list of digits (e.g. if we are combining 2 and 3, add
        // 23 to this condensed list instead of 2 and 3)

        for (int j = 0; j < num_digits; j++) {
                 
            if (j == 0)

                condensed_num.push_back(digits[j]);

            else {
                
                if (sign_combos[i][j - 1] == 'c') {
                    condensed_num[condensed_num.size() - 1] *= 10;
                    condensed_num[condensed_num.size() - 1] += digits[j];
                } else {
                    condensed_num.push_back(digits[j]);
                }
                    
            } 

        }

        int cond_len = condensed_num.size();
        int curr_sum = condensed_num[0]; 
       
        int cond_pos = 1;
        int sign_pos = 0;

        // iterate through the condensed list and sign list, calculating the
        // sum of the combination
        // 
        // e.g. 1 + 2 + 3 - 45 + 67 + 89 = 117 

        while (cond_pos < cond_len) {

            while (sign_combos[i][sign_pos] == 'c')
               sign_pos++; 
            
            if (sign_combos[i][sign_pos] == '+') {
                curr_sum += condensed_num[cond_pos++]; 
            } else {
                curr_sum -= condensed_num[cond_pos++];
            }

            sign_pos++;

        } 

        // print out the sum if the combination adds up to the desired sum

        if (curr_sum == sum) {

            for (int dig = 0; dig < num_digits; dig++) {
                
                if (dig != num_digits - 1) {
                    if (sign_combos[i][dig] == 'c')
                        cout << digits[dig];
                    else
                        cout << digits[dig] << " " << sign_combos[i][dig] << " ";
                } else
                    cout << digits[dig] << "\n";
            
            }

        }

        // clear the vector for the next group of digits
        condensed_num.erase(condensed_num.begin(), condensed_num.end());

    } 
}
