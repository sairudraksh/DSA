class Solution {
public:
    unordered_map<int,int>map;
    vector<int>v;
    int find(vector<int>&nums,int i){
        if(i>=nums.size()) return 0;
        if(v[i]!=-1) return v[i];
        int notTake=find(nums,i+1);
        int j=i+1;
        while(j<nums.size() && nums[j]==nums[i]){
            j++;
        }
        while(j<nums.size() && nums[j]==nums[i]+1){
            j++;
        }
        int take=nums[i]*map[nums[i]]+find(nums,j);
        return v[i]=max(take,notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        v.resize(n+1,-1);
        return find(nums,0);
    }
};