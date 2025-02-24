class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        int count=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i<n-1 && nums[i]==nums[i+1] ) count++;
            else{
                if(count>(n/3)){
                    v.push_back(nums[i]);
                }
                count=1;
            }
        }
        return v;
    }
};