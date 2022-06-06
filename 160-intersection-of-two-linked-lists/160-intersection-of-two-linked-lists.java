/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int a = size(headA);
        int b = size(headB);
        
        while(a>b)
        {
            headA = headA.next;
            a--;
        }
        while(a<b)
        {
            headB = headB.next;
            b--;
        }
        while(headA != headB)
        {
            headA = headA.next;
            headB = headB.next;
            
            if(headA == null)
                return null;
        }
        return headA;
    }
    
    int size(ListNode node)
    {
        int count=0;
        while(node != null)
        {
            count++;
            node = node.next;
        }
        return count;
    }
}