class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* a=head;
        while(a!=NULL && a->val==val){
            a=a->next;
            head=head->next;
        }
        if(a==NULL) return NULL;
        ListNode* b=a->next;
        while(b!=NULL){
            if(b->val==val){
                a->next=b->next;
                b=b->next;
            }
            else{
                b=b->next;
                a=a->next;
            }
        }
        return head;

    }
};