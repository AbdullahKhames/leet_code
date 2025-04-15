#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* first = nullptr;
        ListNode* second = nullptr;
        ListNode* third = nullptr;
        ListNode* last = nullptr;
        int counter = 0;
        while (temp != nullptr)
        {
            counter++;
            first = temp;
            second = first->next;
            third = second->next;
            if (second != nullptr)
            {
                second->next = first;
                if (last != nullptr)
                {
                    first->next = last;
                }else{
                    first->next = nullptr;

                }
                
            }
            if (counter > 1)
            {
                last = first;
            }
            
            
            temp = third;
        }

        head = third;
        return third;

        
    }
void printAll(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) { // Iterate until temp reaches the end (nullptr)
        cout << temp->val << endl;
        temp = temp->next; // Move to the next node
    }
}
};

int main(){
    ListNode number1(1);
    ListNode number2(2, &number1);
    ListNode number3(3, &number2);
    ListNode number4(4, &number3);
    ListNode number5(5, &number4);
    ListNode number6(6, &number5);
    ListNode number7(7, &number6);


    Solution s;
    s.printAll(&number7);
    ListNode* lptr = s.reverseList(&number7);
    s.printAll(lptr);

    return (0);
}
