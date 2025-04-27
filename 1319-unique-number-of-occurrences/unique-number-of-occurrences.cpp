class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        unordered_map<int,int>m;
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto ele :m){
            st.insert(ele.second);
        }
        if(m.size()!=st.size()){
            return false;
        }
        else return true;
    }
};