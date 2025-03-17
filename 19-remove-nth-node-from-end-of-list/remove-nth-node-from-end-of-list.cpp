class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int size=1;
        while(temp->next!=NULL){
            size++;
            temp=temp->next;  
        }
        if(size==n){
            head=head->next;
            return head;
        }
        int len=size-n-1;
        ListNode* tempp=head;
        for(int i=1;i<=len;i++){
            tempp=tempp->next;
        }
        tempp->next=tempp->next->next;
        return head;
    }
};