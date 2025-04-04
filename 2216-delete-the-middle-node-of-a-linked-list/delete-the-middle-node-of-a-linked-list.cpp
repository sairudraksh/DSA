class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow =head;
        if(head->next==NULL) return NULL;
        while(fast->next->next!=NULL){
            fast=fast->next->next;
            if(fast==NULL || fast->next==NULL) break;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};