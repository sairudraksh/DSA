class Solution {
public:
    int reverse(int n){
        int k=0;
        while(n>0){
            k=k*10;
            k=k+(n%10);
            n=n/10;
        }
        return k;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            int rev=reverse(nums[i]);
            st.insert(nums[i]);
            st.insert(rev);
        }
        return st.size();
    }
};