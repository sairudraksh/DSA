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
    void reorderList(ListNode* head) {
        if(head==NULL) return;
        else if(head->next==NULL) return;
        ListNode* s=head;
        ListNode* f=head;
        ListNode* tempa=head;
        while(f->next!=NULL && f->next->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        ListNode* t=s->next;
        s->next=NULL;
        ListNode* c=reverse(t);
        ListNode* tempc=new ListNode(100);
        ListNode* tempb=c;
        while(tempa!=NULL && tempb!=NULL){
            tempc->next=tempa;
            tempa=tempa->next;
            tempc=tempc->next;
            tempc->next=tempb;
            tempb=tempb->next;
            tempc=tempc->next;
        }
        tempc->next=tempa;
        head=c->next;
    }
};