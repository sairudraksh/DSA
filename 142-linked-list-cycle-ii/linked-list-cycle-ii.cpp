class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        bool found=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                found=true;
                break;
            }
        }
        if(found==false) return NULL;

        ListNode* temp=head;
        while(slow!=temp){
            slow=slow->next;
            temp=temp->next;
        }
        return slow;
    }
};