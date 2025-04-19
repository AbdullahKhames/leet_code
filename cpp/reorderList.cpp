struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // here the slow pointer at the middle! revers it!

    ListNode* prev = nullptr;
    ListNode* temp = nullptr;
    ListNode* current = slow->next;
    slow->next = nullptr;
    while (current)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    
    ListNode *first = head;
    ListNode *second = prev;
    while (second != nullptr) {
        ListNode *tmp1 = first->next;
        ListNode *tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
    }

}
