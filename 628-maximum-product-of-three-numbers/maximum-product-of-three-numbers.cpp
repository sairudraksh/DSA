class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int i=n-1;
       int j=n-2;
       int ans=INT_MIN;
       int k=0;
       while(k<j){
        ans=max(ans,nums[i]*nums[j]*nums[k]);
        k++;
        if(nums[i]*nums[j]*nums[k]<ans) break;
       }
       i=0;
       j=1;
       k=n-1;
       while(k>j){
        ans=max(ans,nums[i]*nums[j]*nums[k]);
        k--;
        if(nums[i]*nums[j]*nums[k]<ans) break;
       }
       return ans;
    }
};