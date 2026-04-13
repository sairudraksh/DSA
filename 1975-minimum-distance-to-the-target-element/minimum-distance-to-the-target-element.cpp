class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) v.push_back(i);
        }
        int minimum=INT_MAX;
        for(int i=0;i<v.size();i++){
            minimum=min(minimum,abs(v[i]-start));
        }
        return minimum;
    }
};