class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            auto v1=ans[ans.size()-1];
            auto v2=nums[i];
            if(v1[1]>=v2[0]){
                ans.pop_back();
                ans.push_back({min(v1[0],v2[0]),max(v1[1],v2[1])});
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};