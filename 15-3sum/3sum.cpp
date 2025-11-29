class Solution {
public:
    int n;
    vector<vector<int>>result;
    void find(vector<int>&nums,int &target,int i,int j){
        while(i<j){
            if(nums[i]+nums[j]>target) j--;
            else if(nums[i]+nums[j]<target) i++;
            else{
                while(i<j && nums[i]==nums[i+1]) i++;
                while(j>i && nums[j]==nums[j-1]) j--;
                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        n=nums.size();
        if(n<3) return {};
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int target=-nums[i]; // so (n1+n2+n3==0) but we convert this problem to two sum by (n2+n3=-n1);
            if(i!=0 && nums[i]==nums[i-1]) continue;

            find(nums,target,i+1,n-1);
        }
        return result;
    }
};