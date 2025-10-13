class Solution {
public:
    map<vector<int>,int>map;
    vector<vector<int>>finalans;
    int n;
    void find(vector<int>&nums,int i,vector<int>&ans){
        if(i>=n){
            if(map.find(ans)==map.end()){
                finalans.push_back(ans);
                map[ans]++;
            }
            return;
        }

        ans.push_back(nums[i]);
        find(nums,i+1,ans);
        ans.pop_back();
        find(nums,i+1,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        vector<int>v;
        find(nums,0,v);
        return finalans;
    }
};