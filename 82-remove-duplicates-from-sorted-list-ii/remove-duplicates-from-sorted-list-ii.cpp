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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        unordered_map<int,int>map;

        ListNode* temp=head;
        ListNode* dummy=new ListNode(NULL);
        ListNode* t=dummy;
        while(temp!=NULL){
            map[temp->val]++;
            temp=temp->next;
        }

        temp=head;
        while(temp!=NULL){
            int value=temp->val;

            if(map[value]==1){
                ListNode* newNode=new ListNode(value);
                t->next=newNode;
                t=t->next;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};