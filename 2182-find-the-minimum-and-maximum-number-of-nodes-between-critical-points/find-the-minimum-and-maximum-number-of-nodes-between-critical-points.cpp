class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx=1;
        int stidx=-1;
        int lstidx=-1;
        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* c=head->next->next;
        if(c==NULL) return {-1,-1};
        while(c){
            if((b->val > a->val && b->val>c->val) || (b->val < a->val && b->val<c->val)){
                if(stidx==-1) stidx=idx;
                else lstidx=idx;
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }
        if(lstidx==-1) return {-1,-1};
        int maxd=lstidx-stidx;
        int minidx=INT_MAX;
        idx=1;
        stidx=-1;
        lstidx=-1;
        a=head;
        b=head->next;
        c=head->next->next;
        while(c){
            if((b->val > a->val && b->val>c->val) || (b->val < a->val && b->val<c->val)){
                stidx=lstidx;
                lstidx=idx;
                if(stidx!=-1){
                    int d=lstidx-stidx;
                    minidx=min(minidx,d);
                }
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }
        return {minidx,maxd};
        
    
    }
};