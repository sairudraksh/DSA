class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=queries.size();
        vector<int>ans(m);
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<m;i++){
            int len=0;
            for(int j=0;j<n;j++){
                if(nums[j]>queries[i]) break;
                else len++;
            }
            ans[i]=len;
        }
        return ans;
    }
};