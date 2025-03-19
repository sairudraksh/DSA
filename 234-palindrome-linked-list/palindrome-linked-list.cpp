class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* c=new ListNode(100);
        ListNode* temp=head;
        ListNode* tempC=c;
        while(temp){
            ListNode* node=new ListNode(temp->val);
            tempC->next=node;
            tempC=tempC->next;
            temp=temp->next;
        }
        c=c->next;
        c=reverse(c);
        ListNode* a=head;
        ListNode* b=c;
        while(a){
            if(a->val!=b->val) return false;
            a=a->next;
            b=b->next;
        }
        return true;
    }
};