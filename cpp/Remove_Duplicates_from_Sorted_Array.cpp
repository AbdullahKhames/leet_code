#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    void swap(vector<int> &nums, int x, int y)
    {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    int removeDuplicates(vector<int> &nums)
    {
        int counter = 0, i = 0, j;
        while (i <= (int)nums.size() - 1)
        {
            j = i;
            while (nums[j] == nums[j + 1])
            {
                nums[j] = -1;
                j++;
            }

            i = j + 1;
        }
        int swapped = 0;
        for (i = 0; i < (int)nums.size() - 1; i++)
        {
            swapped = 0;
            for (j = i; j < (int)nums.size(); j++)
            {
                if (nums[i] == -1 && nums[j] != -1)
                {
                    swap(nums, i, j);
                    swapped = 1;
                    break;
                }
            }
            if (!swapped)
            {
                break;
            }
        }
        for (i = 0; i < (int)nums.size(); i++)
        {
            if (nums[i] == -1)
            {
                break;
            }
            counter++;
        }
        // for (i = 0; i < (int)nums.size(); i++)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        return (counter);
    }
};

int main()
{
    Solution solution;
    vector<int> tokens1 = {1, 1, 2};

    cout
        << solution.removeDuplicates(tokens1) << endl;

    vector<int> tokens2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    cout
        << solution.removeDuplicates(tokens2) << endl;
    vector<int> tokens3 = {1, 1};

    cout
        << solution.removeDuplicates(tokens3) << endl;
    return (0);
}
