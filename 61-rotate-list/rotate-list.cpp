/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int n=0;
        ListNode* t=head;
        ListNode* tail=head;
        while(t!=NULL){
            if(t->next==NULL) tail=t;
            n++;
            t=t->next;
        }
        k=k%n;
        if(k==0) return head;
        int x=n-k;
        ListNode* temp=head;
        for(int i=1;i<x;i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};