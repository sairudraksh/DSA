class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int sum=0;
            if(temp1)sum+=temp1->val;
            if(temp2)sum+=temp2->val;
            sum+=carry;
            ListNode* t=new ListNode(sum%10);
            temp->next=t;
            temp=temp->next;
            carry=sum/10;
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
        }
        if(carry){
            ListNode* te=new ListNode(carry);
            temp->next=te;
        }
        return dummy->next;
    }
};