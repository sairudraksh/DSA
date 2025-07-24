class Solution {
public:
    map<vector<int>,int>map;
    vector<vector<int>>finalans;
    void find(vector<int>&nums,int i,vector<int>&ans){
        if(map.find(ans)==map.end()){
            finalans.push_back(ans);
            map[ans]++;
        }
        if(i>=nums.size()) return;
        find(nums,i+1,ans);
        ans.push_back(nums[i]);
        find(nums,i+1,ans);
        ans.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>arr;
        find(nums,0,arr);
        return finalans;
    }
};