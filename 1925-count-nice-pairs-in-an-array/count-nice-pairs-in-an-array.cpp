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
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;
        int count=0;
        for(int i=0;i<n;i++){
            int rev=reverse(nums[i]);
            int key=nums[i]-rev;
            count=count%1000000007;
            if(map[key]>=1) count=map[key]+count;
            map[key]++;
        }
        return count%1000000007;
    }
};