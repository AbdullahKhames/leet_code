#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * this is a brute force approcah to solving this problem
     * better solution is using hashmap
    */
    string frequencySort(string s) {
        const int size = 256;
        char idx = 0;
        int charFreq[size];
        string result = "";
        for (size_t i = 0; i < size; i++)
        {
            charFreq[i] = 0;
        }
        for (size_t i = 0; i < s.size(); i++)
        {
            charFreq[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            int max = INT_MIN;
            for (int j = 0; j < size; j++)
            {
                if (max < charFreq[j])
                {
                    max = charFreq[j];
                    idx = j;
                }
            }
            for (size_t i = 0; i < max; i++)
            {
                result += idx;
            }   
            charFreq[idx] = 0;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    string s = "tree";
    cout << solution.frequencySort(s) << endl;
    s = "cccaaa";
    cout << solution.frequencySort(s) << endl;
    s = "Aabb";
    cout << solution.frequencySort(s) << endl;
    return 0;
}