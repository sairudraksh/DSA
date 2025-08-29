class Solution {
public:
    int n;
    vector<vector<int>>finalans;
    void find(vector<int>& nums,vector<int>&v){
        bool flagg=false;
        for(int i=0;i<n;i++){
            if(nums[i]==INT_MIN) continue;

            flagg=true;
            int orgnums=nums[i];

            v.push_back(nums[i]);
            nums[i]=INT_MIN;

            find(nums,v);

            nums[i]=orgnums;
            v.pop_back();
        }
        if(flagg==false) finalans.push_back(v);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int>v;
        find(nums,v);
        return finalans;
    }
};