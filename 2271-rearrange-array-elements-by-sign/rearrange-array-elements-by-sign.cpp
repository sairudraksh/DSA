class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v1;
        vector<int>v2;

        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        int i=0;
        int j=0;
        vector<int>ans;
        while(i<v1.size() && j<v2.size()){
            ans.push_back(v1[i]);
            ans.push_back(v2[i]);
            i++;
            j++;
        }
        return ans;
    }
};