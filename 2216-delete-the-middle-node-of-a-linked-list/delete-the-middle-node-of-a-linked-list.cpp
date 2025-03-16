class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head->next==NULL){
            return NULL;
        }
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            if(fast->next==NULL) break;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;    
    }
};