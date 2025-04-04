class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* temp=head;
        int n=1;
        while(temp->next!=NULL){
            temp=temp->next;
            n++;
        }
        temp->next=head;
        if(k>=n) k=k%n;
        ListNode* t=head;
        for(int i=1;i<n-k;i++){
            t=t->next;
        }
        ListNode* h=t->next;
        t->next=NULL;
        return h;
    }
};