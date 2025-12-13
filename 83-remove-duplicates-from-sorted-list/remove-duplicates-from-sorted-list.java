/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null) return null;
        if(head.next==null) return head;
        while(head.next!=null && head.val==head.next.val){
            head=head.next;
        }
        ListNode temp=head;
        ListNode t=head;
        while(t!=null){
            while(t!=null && temp.val==t.val){
                t=t.next;
            }
            temp.next=t;
            temp=t;
            if(t!=null) t=t.next;
        }
        return head;
    }
}