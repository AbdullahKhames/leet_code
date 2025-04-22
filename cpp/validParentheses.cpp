#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char current;
        bool isValid = true;
        if (s.length() < 2) {
            return false;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' ||
                s[i] == '[' ||
                s[i] == '{')
            {
                st.push(s[i]);
            } else {
                if(!st.empty()) {
                    current = st.top();
                    st.pop();
                    if ((s[i] == ')' && current != '(') ||
                        (s[i] == ']' && current != '[') ||
                        (s[i] == '}' && current != '{')
                        )
                    {
                        isValid = false;
                        break;
                    }
                } else {
                    isValid = false;
                    break;
                }
                
            }
        }
        if (st.size() > 0) {
            isValid = false;
        }
        return isValid;
    }
};


int main() {
    Solution solution;
    cout << "is valid paranthesis ()[]{} should be true ! : " << solution.isValid("()[]{}") << endl;
    cout << "is valid paranthesis (] should be false ! : " << solution.isValid("(]") << endl;
    cout << "is valid paranthesis ([]) should be true ! : " << solution.isValid("([])") << endl;
    cout << "is valid paranthesis (( should be false ! : " << solution.isValid("((") << endl;
}
