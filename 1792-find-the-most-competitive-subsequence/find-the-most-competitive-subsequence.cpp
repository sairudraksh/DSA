class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>st;

        for(int i=0;i<nums.size();i++){
            while(st.size()>0 && nums[i]<st.back() && (nums.size()-(i+1))+st.size()>=k){
                st.pop_back();
            }

            if(st.size()<k) st.push_back(nums[i]);
        }
        return st;
    }
};