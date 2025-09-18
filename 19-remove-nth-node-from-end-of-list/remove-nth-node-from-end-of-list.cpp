class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL && n==1) return NULL;
        else if(head->next==NULL && n==0) return head;

        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }

        if(count==n){
            head=head->next;
            return head;
        }
        int k=count-n;
        temp=head;
        for(int i=1;i<k;i++){
            temp=temp->next;
        }

        temp->next=temp->next->next;
        return head;
    }
};