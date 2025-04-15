#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int score = 0, low = 0, high = (int)tokens.size() - 1, current = 0;
        while (low <= high)
        {
            if (power >= tokens[low])
            {
                power -= tokens[low++];
                current++;
                score = max(score, current);
            }
            else if (score >= 1)
            {
                power += tokens[high--];
                current--;
            }
            else
            {
                break;
            }
        }

        return score;
    }
};

int main()
{
    Solution solution;
    vector<int> tokens1 = {100};
    int power = 50;

    cout
        << solution.bagOfTokensScore(tokens1, power) << endl;

    vector<int> tokens2 = {200, 100};
    power = 150;

    cout
        << solution.bagOfTokensScore(tokens2, power) << endl;

    vector<int> tokens3 = {100, 200, 300, 400};
    power = 200;

    cout
        << solution.bagOfTokensScore(tokens3, power) << endl;
    return (0);
}
