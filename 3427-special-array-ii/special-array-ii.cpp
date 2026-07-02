class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>v(n,0);
        for(int j=1;j<n;j++){
            if(nums[j]%2==0 && nums[j-1]%2!=0){
                v[j]=1;
            }
            else if(nums[j]%2!=0 && nums[j-1]%2==0){
                v[j]=1;
            }
            else v[j]=0;
        }
        vector<int>v2=v;
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int idx1=queries[i][0];
            int idx2=queries[i][1];
            if(idx1==idx2){
                ans.push_back(true);
                continue;
            }
            int sum=0;
            if(idx1==0){
                sum=v[idx2];
            }
            else sum=v[idx2]-v[idx1];

            if(v2[idx2]==1 && sum>=idx2-idx1){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};