class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            auto v1=nums[i];
            auto v2=v[v.size()-1];

            if(v2[1]>=v1[0]){
                v.pop_back();
                v.push_back({min(v1[0],v2[0]),max(v1[1],v2[1])});
            }
            else{
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};