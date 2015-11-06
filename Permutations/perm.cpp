#include <iostream>
#include <vector>

using std::vector;
using std::cout;

void perm(vector<int> list, vector<vector<int> > &results);
double fact(int i);

int main(int argc, char **argv)
{
    vector<int> list;
    vector<vector<int> > results; 
    
    for (int i = 1; i < argc; i++) {
        list.push_back(atoi(argv[i]));    
    }
   
    perm(list, results); 
   
    for (int i = 0; i < (int) results.size(); i++) {
        vector<int> result = results[i];
        for (int j = result.size() - 1; j >= 0; j--) {
            cout << result[j] << " ";
        }
        cout << "\n";
    }
   

    return 0;

}

void perm(vector<int> list, vector<vector<int> > &results) 
{
    int len = list.size(); 
   
    if (len == 2) {
   
        vector<int> result;
        result.push_back(list[0]);
        result.push_back(list[1]);
        results.push_back(result);

        int temp = result[0];
        result[0] = result[1];
        result[1] = temp;
        results.push_back(result);

    } else {
    
        for (size_t i = 0; i < list.size(); i++) {
            
            vector<int> spliced_list;

            for (size_t j = 0; j < list.size(); j++) {
                if (j != i)
                   spliced_list.push_back(list[j]);
            } 

            perm(spliced_list, results);

            int to_add = fact(len - 1);
            for (int k = 0; k < to_add; k++) {      
                results[results.size() - k - 1].push_back(list[i]);
            }

        } 

    }

}

double fact(int i)
{
    if (i < 2)
        return 1;
    else 
        return i * fact(i - 1);
}
