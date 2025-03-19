class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode* slow=head;  
        ListNode* fast=head;
        ListNode* a=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* b=slow->next;
        b=reverse(b);
        slow->next=NULL;
        while(b!=NULL){
            if(a->val!=b->val) return false;
            b=b->next;
            a=a->next;
        }
        return true;
    }
};