class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lo=new ListNode(50);
        ListNode *hi=new ListNode(100);
        ListNode *templo=lo;
        ListNode *temphi=hi;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                lo->next=temp;
                lo=lo->next;
                temp=temp->next;
            }
            else{
                hi->next=temp;
                hi=hi->next;
                temp=temp->next;
            }
        }
        lo->next=temphi->next;
        hi->next=NULL;
        return templo->next;
    }
};