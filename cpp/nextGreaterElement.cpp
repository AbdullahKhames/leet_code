#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int targetJ;
        int targetVal;
        int nextGreaterElement;
        for (int i = 0; i < nums1.size(); i++)
        {
            targetJ = -1;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    targetJ = j;
                    break;
                }
                
            }
            if (targetJ != -1)
            {
                targetVal = nums2[targetJ];
                nextGreaterElement = -1;
                for (int j = targetJ + 1; j <  nums2.size(); j++)
                {
                    if (nums2[j] > targetVal)
                    {
                        nextGreaterElement = nums2[j];
                        break;
                    }
                }
                result.push_back(nextGreaterElement);
            }
        }
        return result;
    }
};

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1_1 = {4,1,2};
    vector<int> nums2_1 = {1,3,4,2};
    vector<int> expected1 = {-1,3,-1};
    vector<int> result1 = solution.nextGreaterElement(nums1_1, nums2_1);

    cout << "Test Case 1:\n";
    cout << "nums1 = "; printVector(nums1_1);
    cout << ", nums2 = "; printVector(nums2_1);
    cout << "\nExpected Output: "; printVector(expected1);
    cout << "\nActual Output: "; printVector(result1);
    cout << "\n\n";

    // Test Case 2
    vector<int> nums1_2 = {2,4};
    vector<int> nums2_2 = {1,2,3,4};
    vector<int> expected2 = {3,-1};
    vector<int> result2 = solution.nextGreaterElement(nums1_2, nums2_2);

    cout << "Test Case 2:\n";
    cout << "nums1 = "; printVector(nums1_2);
    cout << ", nums2 = "; printVector(nums2_2);
    cout << "\nExpected Output: "; printVector(expected2);
    cout << "\nActual Output: "; printVector(result2);
    cout << "\n";

    return 0;
}
