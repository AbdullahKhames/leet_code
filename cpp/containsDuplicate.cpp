#include "base.h"


bool containsDuplicate(vector<int>& nums) {
    map<int, int> frequency;
    for(int num: nums) {
        frequency[num]++;
    }
    for (auto entry : frequency) {
        if (entry.second > 1) {
            return true;
        }
    }
    return false;
}

void runTest(const vector<int>& nums, bool expected) {
    vector<int> copy = nums;  // To match non-const reference signature
    bool result = containsDuplicate(copy);

    cout << "Input: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]\nExpected: " << (expected ? "true" : "false")
         << ", Actual: " << (result ? "true" : "false") << "\n\n";
}

int main() {
    runTest({1, 2, 3, 1}, true);
    runTest({1, 2, 3, 4}, false);
    runTest({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true);
    runTest({1000000, -1000000}, false);
    runTest({0, 0}, true);

    return 0;
}
