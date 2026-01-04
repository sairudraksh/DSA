class Solution {
public:
    int find(int n){
        int count=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                count++;
                sum+=i;
            }
            if(count>4) return 0;
        }
        if(count==4) return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int a=find(nums[i]);
            ans+=a;
        }
        return ans;
    }
};