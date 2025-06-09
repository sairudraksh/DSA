class Solution {
public:
    int find(int n){
        int sum=0;
        while(n>0){
            int nums=n%10;
            sum=sum*10+nums;
            n=n/10;
        }
        return sum;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            int ans=find(nums[i]);
            s.insert(ans);
        }
        return s.size();
    }
};