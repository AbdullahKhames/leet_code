package easy.merge_two_lists;

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode current, next, toReturn = null;

        next = new ListNode();
        current = new ListNode();
        current.val = Math.min(list1.val, list2.val);
        toReturn = current;
        while (list1 != null && list2 != null){
            if (list1.val < list2.val){
                current.val = list1.val;
                if (list1.next != null && list1.next.val < list2.val){
                    next.val = list1.next.val;

                } else if (list1.next != null) {
                    next.val = list2.val;
                }
                list1 = list1.next;
            }
            else {
                current.val = list2.val;
                if (list2.next != null && list2.next.val < list1.val){
                    next.val = list2.next.val;
                } else if (list2.next != null) {
                    next.val = list1.val;
                }
                list2 = list2.next;
            }
        }
//        while (list != null){
//
//            list = list.next;
//        }
//        while ( list2 != null){
//
//            list2 = list2.next;
//        }
        return toReturn;
    }
}