class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        vector<vector<int>>ans;

        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<int>v=nums[i];
            sort(v.begin(),v.end());
            ans.push_back(v);
        }
        int m=nums[0].size();
        int total=0;
        for(int i=0;i<m;i++){
            int maximum=INT_MIN;
            for(int j=0;j<n;j++){
                maximum=max(maximum,ans[j][i]);
            }
            total+=maximum;
        }
        return total;

    }
};