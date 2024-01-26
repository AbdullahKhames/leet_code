// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 2)
        {
            return {0, 1};
        }
        int bIter = 0, eIter = nums.size() - 1;
        while (bIter < eIter)
        {
            if (nums[bIter] + nums[eIter] == target)
            {
                return {bIter, eIter};
            } else {
                for (int i = bIter, j = eIter; i < j; j--)
                {
                   if (nums[i] + nums[j] == target)
                    {
                    return {i, j};
                    }
                }
                bIter++;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution s;

    // Create a named vector and then pass it to the function
    vector<int> inputVector = {-1,-2,-3,-4,-5};
    vector<int> v = s.twoSum(inputVector, -8);

    cout << "Solution is: ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}
