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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right) return head;
        if(left == 1){
            ListNode* t2 = head;
            for(int i = 1; i < right; i++){
                t2 = t2->next;
            }
            ListNode* temp2 = t2->next;
            t2->next = NULL;
            ListNode* c = reverse(head);
            head->next = temp2;
            return c;
        }
        ListNode* t1=head;
        ListNode* t2=head;
        ListNode* temp1=head;
        ListNode* temp2=head;
        for(int i=1;i<left-1;i++){
            t1=t1->next;
        }
        temp1=t1->next;
        for(int i=1;i<right;i++){
            t2=t2->next;
        }
        temp2=t2->next;
        t2->next=NULL;
        ListNode* c=reverse(temp1);
        t1->next=c;
        temp1->next=temp2;
        return head;
    }
};