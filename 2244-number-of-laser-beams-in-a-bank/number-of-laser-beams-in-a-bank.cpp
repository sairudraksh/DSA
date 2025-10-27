class Solution {
public:
    int numberOfBeams(vector<string>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        int prev=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(nums[i][j]=='1') count++;
            }
            ans+=(count*prev);
            if(count!=0) prev=count;
        }
        return ans;
    }
};