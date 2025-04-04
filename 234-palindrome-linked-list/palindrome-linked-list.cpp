class Solution {
public:
    ListNode* reverse(ListNode* head) {
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
    bool isPalindrome(ListNode* head) {
        ListNode* c=new ListNode(100);
        ListNode* temp=head;
        ListNode* t=c;
        while(temp!=NULL){
            ListNode* node=new ListNode(temp->val);
            t->next=node;
            t=t->next;
            temp=temp->next;
        }
        c=c->next;
        c=reverse(c);
        temp=head;
        ListNode* b=c;
        while(temp){
            if(temp->val!=b->val){
                return false;
            }
            temp=temp->next;
            b=b->next;
        }
        return true;
    }
};