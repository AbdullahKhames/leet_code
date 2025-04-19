#include <iostream>

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* merged;
    ListNode* head;
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;

    if (!list1) {
        merged = list2;
        return merged;
    }
    if (!list2) {
        merged = list1;
        return merged;
    }
    if (temp1->val < temp2->val) {
        head = new ListNode(temp1->val);
        temp1 = temp1->next;
    } else {
        head = new ListNode(temp2->val);
        temp2 = temp2->next;
    }
    merged = head;
    while (temp1 && temp2) {
        if (temp1->val < temp2->val) {
                merged->next = new ListNode(temp1->val);
                merged = merged->next;
                temp1 = temp1->next;
        } else {
                merged->next = new ListNode(temp2->val);
                merged = merged->next;
                temp2 = temp2->next;
        }
    }
    while (temp1) {
        merged->next = new ListNode(temp1->val);
        merged = merged->next;
        temp1 = temp1->next;
    }
    while (temp2) {
        merged->next = new ListNode(temp2->val);
        merged = merged->next;
        temp2 = temp2->next;
    }
    return head;
}


int main () {
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* head = mergeTwoLists(list1, list2);
    return 0;
}
