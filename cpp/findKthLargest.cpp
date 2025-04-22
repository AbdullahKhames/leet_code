#include "base.h"

class Solution
{
public:
    // void swap(vector<int> &nums, int x, int y) {
    //     int temp = nums[x];
    //     nums[x] = nums[y];
    //     nums[y] = temp;
    // }
    int findKthLargest(vector<int> &nums, int k)
    {
        // int maxIdx;
        // for (int i = 0; i < nums.size() - 1; i++)
        // {
        //     maxIdx = i;
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[j] >= nums[maxIdx])
        //         {
        //             maxIdx = j;
        //         }
        //     }
        //     if (maxIdx != i)
        //     {
        //         swap(nums, maxIdx, i);
        //     }
        // }
        // return nums[k - 1];
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        int size = nums.size() - k + 1;
        while (!pq.empty() && pq.size() != size)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }

};

int main()
{
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    int expected1 = 5;
    int result1 = solution.findKthLargest(nums1, k1);

    cout << "Test Case 1:\n";
    cout << "nums = [3,2,1,5,6,4], k = 2\n";
    cout << "Expected Output: " << expected1 << "\n";
    cout << "Actual Output: " << result1 << "\n\n";

    // Test Case 2
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    int expected2 = 4;
    int result2 = solution.findKthLargest(nums2, k2);

    cout << "Test Case 2:\n";
    cout << "nums = [3,2,3,1,2,4,5,5,6], k = 4\n";
    cout << "Expected Output: " << expected2 << "\n";
    cout << "Actual Output: " << result2 << "\n\n";

    // Test Case 3
    vector<int> nums3 = {1};
    int k3 = 1;
    int expected3 = 1;
    int result3 = solution.findKthLargest(nums3, k3);

    cout << "Test Case 3:\n";
    cout << "nums = [1], k = 1\n";
    cout << "Expected Output: " << expected3 << "\n";
    cout << "Actual Output: " << result3 << "\n\n";

    return 0;
}
