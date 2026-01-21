
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int x=n/2;
        temp=head;
        for(int i=0;i<x-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};