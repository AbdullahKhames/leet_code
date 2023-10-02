package easy.merge_two_lists;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SolutionTest {
    Solution solution;
    ListNode listNode1;
    ListNode listNode2;
    ListNode listNode3;
    ListNode listNode4;
    ListNode listNode5;
    ListNode listNode6;

    @BeforeEach
    void setUp() {
        solution = new Solution();
        listNode1 = new ListNode(1);
        listNode2 = new ListNode(3);
        listNode3 = new ListNode(5);
        listNode4 = new ListNode(6);
        listNode5 = new ListNode(7);
        listNode6 = new ListNode(9);

        listNode1.next = listNode3;
        listNode3.next = listNode6;
        listNode2.next = listNode4;
        listNode4.next = listNode5;

    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void mergeTwoLists() {
        System.out.println(solution.mergeTwoLists(listNode1, listNode2));
    }
}