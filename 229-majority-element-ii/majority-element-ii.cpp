class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k=nums.size()/3;
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i=0;i<nums.size()-k;i++){
            if(nums[i]==nums[i+k]){
                if(v.size()>0 && v[v.size()-1]!=nums[i])v.push_back(nums[i]);
                else if(v.size()==0) v.push_back(nums[i]);
            }
        }
        return v;
    }
};