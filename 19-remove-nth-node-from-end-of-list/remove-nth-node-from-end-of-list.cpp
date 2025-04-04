class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int size=0;
        if(head->next==NULL && n==1) return NULL;
        else if(head->next==NULL && n==0) return head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        if(size==n){
            head=head->next;
            return head;
        }
        int k=size-n;
        temp=head;
        for(int i=1;i<k;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};