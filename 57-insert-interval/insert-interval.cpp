class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& interval) {
        int n=nums.size();
        vector<vector<int>>ans;
        int i=0;

        while(i<n && nums[i][1]<interval[0]){
            ans.push_back(nums[i]);
            i++;
        }
        vector<int>v=interval;
        while(i<n && v[1]>=nums[i][0]){
            v[0]=min(v[0],nums[i][0]);
            v[1]=max(v[1],nums[i][1]);
            i++;
        }
        ans.push_back(v);

        while(i<n){
            ans.push_back(nums[i]);
            i++;
        }
        return ans;
    }
};