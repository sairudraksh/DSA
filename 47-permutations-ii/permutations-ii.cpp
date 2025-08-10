class Solution {
public:
    map<vector<int>, int>map;
    vector<vector<int>>finalans;
    void find(vector<int>& nums,vector<int>&ans){
        if(ans.size()==nums.size()){
            if(map.find(ans)==map.end()){
                finalans.push_back(ans);
                map[ans]++;
            }
            return;
        }

        for(int k=0;k<nums.size();k++){
            if(nums[k]==INT_MIN) continue;
            int org=nums[k];

            ans.push_back(nums[k]);
            nums[k]=INT_MIN;

            find(nums,ans);

            ans.pop_back();
            nums[k]=org;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        find(nums,ans);
        return finalans;
    }
};