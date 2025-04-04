class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        int mid=n/2;
        ListNode* t=head;
        for(int i=0;i<mid;i++){
            t=t->next;
        }
        return t;
    }
};