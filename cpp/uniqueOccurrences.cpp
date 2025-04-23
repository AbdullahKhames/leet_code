#include "base.h"

class Solution {

    public:
        int MAX_VAL = 1000;
        bool uniqueOccurrences(vector<int>& arr) {
            map<int,int> frequency;
            set<int> freq;
            for (int i = 0; i < arr.size(); i++)
            {
                frequency[arr[i]]++;
            }
            for (int i = 0; i < frequency.size(); i++)
            {
                if (frequency[i] == 0)
                    frequency[i] = 1001;
            }

            for (auto pair : frequency) {
                if (pair.first == 1001) {
                    continue;
                } else if (freq.find(pair.second) == freq.end()){
                    freq.insert(pair.second);
                } else {
                    return false;
                }
            }

            return true;
        }
    };
void runTest(const vector<int>& arr, bool expected) {
    vector<int> copy = arr;  // Because the function takes a non-const reference
    Solution s;
    bool result = s.uniqueOccurrences(copy);
    
    cout << "Input: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]\nExpected: " << (expected ? "true" : "false")
         << ", Actual: " << (result ? "true" : "false") << "\n\n";
}

int main() {
    runTest({1, 2, 2, 1, 1, 3}, true);
    runTest({1, 2}, false);
    runTest({-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}, true);
    runTest({4, 4, 4, 3, 3, 2, 2, 2, 1}, false); // 4:3, 3:2, 2:3 -> duplicate 3s
    runTest({10}, true); // Only one number with one occurrence

    return 0;
}
