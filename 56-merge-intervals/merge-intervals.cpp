class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        ans.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            auto v=ans[ans.size()-1];
            ans.pop_back();
            if(v[1]>=nums[i][0]){
                ans.push_back({min(nums[i][0],v[0]),max(nums[i][1],v[1])});
            }
            else{
                ans.push_back(v);
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};