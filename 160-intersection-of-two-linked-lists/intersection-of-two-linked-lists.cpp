class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int lenA=0;
        while(tempA!=NULL){// to find len of a;
            lenA++;
            tempA=tempA->next;
        }
        int lenB=0;
        while(tempB!=NULL){//to find len of b;
            lenB++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        int diff=0;
        if(lenA>lenB){//if a is greater
            diff=lenA-lenB;
            for(int i=1;i<=diff;i++){
                tempA=tempA->next;
            }
            while(tempA!=tempB){//check when they are equal or we can say intersect
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;//or tempb;
        }
        else{//if b is less than or equal to a;
            diff=lenB-lenA;
            for(int i=1;i<=diff;i++){
                tempB=tempB->next;
            }
            while(tempA!=tempB){//check when they are equal or we can say intersect
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;//or tempb
        }
    }
};