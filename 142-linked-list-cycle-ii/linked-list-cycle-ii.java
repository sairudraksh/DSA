/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast=head;
        ListNode slow=head;
        boolean found=false;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
            if(slow==fast){
                found=true;
                break;
            }
        }
        if(found==false) return null;
        else{
            ListNode temp=head;
            while(temp!=slow){
                temp=temp.next;
                slow=slow.next;
            }
        }
        return slow;
    }
}