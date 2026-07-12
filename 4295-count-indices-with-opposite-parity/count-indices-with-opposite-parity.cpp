class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>v1(n,0);
        if(nums[n-1]%2==0) v1[n-1]=1;
        vector<int>v2(n,0);
        if(nums[n-1]%2!=0) v2[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]%2==0){
                v1[i]=v1[i+1]+1;
                v2[i]=v2[i+1];
            }
            else{
                v2[i]=v2[i+1]+1;
                v1[i]=v1[i+1];
            }
        }
        vector<int>ans(n,0);
        for(int i=0;i<n-1;i++){
            if(nums[i]%2==0){
                ans[i]=v2[i+1];
            }

            else{
                ans[i]=v1[i+1];
            }
        }

        return ans;
    }
};