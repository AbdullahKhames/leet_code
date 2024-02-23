#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string longestString = "" + s[0];
        int left = 0, right = 1;
        while (right < s.length() && left < right)
        {
            if (s[left] == s[right])
            {
                /* code */
            }
            
        }
        return (longestString.length());
    }
};

int main()
{
    Solution s;
    string key = "abcabcbb";
    cout << s.lengthOfLongestSubstring(key) << endl;
    key = "bbbbb";
    cout << s.lengthOfLongestSubstring(key) << endl;
    key = "pwwkew";
    cout << s.lengthOfLongestSubstring(key) << endl;
    return (0);
}
