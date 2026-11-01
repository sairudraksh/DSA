class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<long long>ans;
        int n=nums.size();
        long long curr=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                curr++;
            }
            else{
                ans.push_back(curr);
                curr=0;
            }
        }
        if(curr>0) ans.push_back(curr);
        long long total=0;
        for(int i=0;i<ans.size();i++){
            long long num=ans[i];
            long long a=(num*(num+1))/2;
            total+=a;
        }
        return total;
    }
};