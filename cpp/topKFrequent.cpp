#include "base.h"

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> frequency;
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            frequency[nums[i]]++;
        }
        for (pair<int, int> pair: frequency)
        {
            pq.push({pair.second, pair.first});
        }
        while(k--) {
            int el = pq.top().second;
            pq.pop();
            result.push_back(el);
        }
        return result;
    }

};

void printVector(const vector<int> &v)
{
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i < v.size() - 1)
            cout << ",";
    }
    cout << "]";
}

int main()
{
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> expected1 = {1, 2}; // Order doesn't matter
    vector<int> result1 = solution.topKFrequent(nums1, k1);

    cout << "Test Case 1:\n";
    cout << "nums = ";
    printVector(nums1);
    cout << ", k = " << k1 << "\nExpected Output: ";
    printVector(expected1);
    cout << "\nActual Output: ";
    printVector(result1);
    cout << "\n\n";

    // Test Case 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> expected2 = {1};
    vector<int> result2 = solution.topKFrequent(nums2, k2);

    cout << "Test Case 2:\n";
    cout << "nums = ";
    printVector(nums2);
    cout << ", k = " << k2 << "\nExpected Output: ";
    printVector(expected2);
    cout << "\nActual Output: ";
    printVector(result2);
    cout << "\n\n";

    // Test Case 3
    vector<int> nums3 = {4, 4, 4, 5, 5, 6};
    int k3 = 2;
    vector<int> expected3 = {4, 5}; // 4 appears 3 times, 5 appears 2 times
    vector<int> result3 = solution.topKFrequent(nums3, k3);

    cout << "Test Case 3:\n";
    cout << "nums = ";
    printVector(nums3);
    cout << ", k = " << k3 << "\nExpected Output: ";
    printVector(expected3);
    cout << "\nActual Output: ";
    printVector(result3);
    cout << "\n";

    return 0;
}
