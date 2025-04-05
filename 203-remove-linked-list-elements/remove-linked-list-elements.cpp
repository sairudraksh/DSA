class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        ListNode* a=head;
        while(a!=NULL && a->val==val){
            head=head->next;
            a=a->next;
        }
        if(head==NULL) return NULL;
        ListNode* temp=head;
        ListNode* t=head->next;
        while(t!=NULL){
            if(t->val==val){
                temp->next=t->next;
                t=t->next;
            }
            else{
                temp=temp->next;
                if(t!=NULL) t=t->next;
            }
        }
        return head;
    }
};