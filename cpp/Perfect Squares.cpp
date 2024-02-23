#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    // int numSquares(int n)
    // {
    //     const int maxPerfectSquaresTo10000 = 100;
    //     int perfectSquares[maxPerfectSquaresTo10000], counterArr[1024];
    //     int currentIdx = 0, counterIdx = 0, counter = 0, sum = 0;
    //     for (int i = n; i > 0; i--)
    //     {
    //         if (isPerfectSquare(i))
    //         {
    //             perfectSquares[currentIdx] = i;
    //             currentIdx++;
    //         }
    //     }
    //     for (int i = 0; i < currentIdx; i++)
    //     {
    //         sum = 0;
    //         counter = 0;
    //         while (sum + perfectSquares[i] <= n)
    //         {
    //             sum += perfectSquares[i];
    //             counter++;
    //         }

    //         for (int j = i; j < currentIdx; j++)
    //         {
    //             if (sum == n)
    //             {
    //                 counterArr[counterIdx] = counter;
    //                 counterIdx++;
    //             }
    //             while (sum + perfectSquares[j] <= n)
    //             {
    //                 sum += perfectSquares[j];
    //                 counter++;
    //             }
    //         }
    //         if (sum == n)
    //         {
    //             counterArr[counterIdx] = counter;
    //             counterIdx++;
    //         }
    //     }
    //     return getMinCounter(counterArr, counterIdx);
    // }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
    bool isPerfectSquare(int x)
    {
        double res = sqrt(x);
        return (int(res) * int(res)) == x;
    }
    int getMinCounter(int counterArr[], int size)
    {
        int min = INT_MAX;
        for (int i = 0; i < size; i++)
        {
            if (counterArr[i] < min)
            {
                min = counterArr[i];
            }
        }
        return (min);
    }
};

int main()
{
    Solution s;
    int n = 12;
    cout << s.numSquares(n) << endl;
    n = 13;
    cout << s.numSquares(n) << endl;
    n = 20;
    cout << s.numSquares(n) << endl;
    n = 6;
    cout << s.numSquares(n) << endl;
    return (0);
}
