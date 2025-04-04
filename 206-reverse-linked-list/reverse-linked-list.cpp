class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        else if(head->next==NULL) return head;
        ListNode* s=head;
        ListNode* f=head->next;
        ListNode* fs=head->next->next;
        head->next=NULL;
        while(f!=NULL){
            f->next=s;
            s=f;
            f=fs;
            if(fs!=NULL) fs=fs->next;
        }
        return s;
    }
};