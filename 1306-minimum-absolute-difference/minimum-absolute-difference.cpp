class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int minimum=INT_MAX;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            minimum=min(minimum,nums[i+1]-nums[i]);
        }
        vector<vector<int>>v;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]==minimum){
                v.push_back({nums[i],nums[i+1]});
            }
        }
        return v;
    }
};