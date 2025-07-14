class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int>ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        int sum=0;
        int k=1;
        for(int i=ans.size()-1;i>=0;i--){
            sum+=ans[i]*k;
            k*=2;
        }
        return sum;
    }
};