class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> pq;
        vector<int>ans(n,-1);

        for(int i=n-1;i>=0;i--){
            while(pq.size()>0 && nums[i]>=nums[pq.top()]){
                pq.pop();
            }

            if(!pq.empty()){
                ans[i]=nums[pq.top()];
            }
            else if(pq.size()==0){
                for(int k=0;k<n;k++){
                    if(nums[k]>nums[i]){
                        ans[i]=nums[k];
                        break;
                    }
                }
            }
            pq.push(i);
        }
        return ans;
    }
};