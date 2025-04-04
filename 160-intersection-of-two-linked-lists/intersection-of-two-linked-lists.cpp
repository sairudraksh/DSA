class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int sizeA=0;
        int sizeB=0;
        while(tempA!=NULL){
            tempA=tempA->next;
            sizeA++;
        }
        while(tempB!=NULL){
            tempB=tempB->next;
            sizeB++;
        }
        int k=0;
        if(sizeA>=sizeB){
            k=sizeA-sizeB;
            for(int i=0;i<k;i++){
                headA=headA->next;
            }
        }
        else{
            k=sizeB-sizeA;
            for(int i=0;i<k;i++){
                headB=headB->next;
            }
        }
        tempA=headA;
        tempB=headB;
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};