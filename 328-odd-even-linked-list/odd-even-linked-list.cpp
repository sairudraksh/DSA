class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        int count=1;
        ListNode* ans=new ListNode(-1);
        ListNode* dummy=ans;
        ListNode* temp=head;
        while(temp!=NULL){
            if(count%2!=0){
                ListNode* t=new ListNode(temp->val);
                dummy->next=t;
                dummy=dummy->next;
            }
            count++;
            temp=temp->next;
        }
        count=1;
        temp=head;
        while(temp!=NULL){
            if(count%2==0){
                ListNode* t=new ListNode(temp->val);
                dummy->next=t;
                dummy=dummy->next;
            }
            count++;
            temp=temp->next;
        }
        return ans->next;
    }
};