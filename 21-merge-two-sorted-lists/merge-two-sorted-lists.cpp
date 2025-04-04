class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tempA=list1;
        ListNode* tempB=list2;
        ListNode* h=new ListNode(100);
        ListNode* head=h;
        while(tempA!=NULL && tempB!=NULL){
            if(tempA->val<=tempB->val){
                h->next=tempA;
                tempA=tempA->next;
                h=h->next;
            }
            else{
                h->next=tempB;
                tempB=tempB->next;
                h=h->next;
            }
        }
        if(tempA==NULL){
            while(tempB!=NULL){
                h->next=tempB;
                tempB=tempB->next;
                h=h->next;
            }
        }
        else if(tempB==NULL){
            while(tempA!=NULL){
                h->next=tempA;
                tempA=tempA->next;
                h=h->next;
            }
        }
        return head->next;
    }
};