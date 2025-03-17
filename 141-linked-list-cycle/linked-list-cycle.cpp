class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
            if(size>500000) return true;
        }
        return false;
    }
};