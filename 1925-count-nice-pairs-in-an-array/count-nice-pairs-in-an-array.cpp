class Solution {
public:
    int reverse(int n){
        int sum=0;
        while(n>0){
            int nums=n%10;
            sum=sum*10+nums;
            n=n/10;
        }
        return sum;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int rev=reverse(nums[i]);
            int key=nums[i]-rev;
            count=count%1000000007;
            if(mp[key]>=1) count=count+mp[key];
            mp[key]++;
        }
        return count%1000000007;
        
    }
};