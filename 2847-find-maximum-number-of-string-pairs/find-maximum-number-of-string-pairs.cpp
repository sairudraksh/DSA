class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& nums) {
        int n=nums.size();
        int count=0;
        unordered_set<string>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            string s=nums[i];
            reverse(s.begin(),s.end());
            if(nums[i]==s)continue;
            if(st.find(s)!=st.end()){ 
                count++;
                st.erase(nums[i]);
            }
        }
        return count;
    }
};