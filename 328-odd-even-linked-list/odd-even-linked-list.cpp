class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* even=head->next;
        ListNode* evenhead=even;

        ListNode* odd=head;
        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;

            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};