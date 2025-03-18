class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* tail=NULL;
        int n=0;
        while(temp!=NULL){
            if(temp->next==NULL) tail=temp;
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0) return head;
        temp=head;
        for(int i=1;i<=n-k-1;i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};