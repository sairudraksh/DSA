class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* lo=new ListNode(100);
        ListNode* hi=new ListNode(10);
        ListNode* tempLo=lo;
        ListNode* tempHi=hi;
        ListNode* temp=head;
        int n=1;
        while(temp!=NULL){
            if(n%2!=0){
                tempLo->next=temp;
                temp=temp->next;
                tempLo=tempLo->next;
                n++;
            }
            else{
                tempHi->next=temp;
                temp=temp->next;
                tempHi=tempHi->next;
                n++;

            }
        }
        tempLo->next=hi->next;
        tempHi->next=NULL;
        return lo->next; 
    }
};