class Solution {
public:
    int find(int n){
        int sum=0;

        while(n>0){
            sum+=(n%10);
            n=n/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int minimum=INT_MAX;
        for(int i=0;i<nums.size();i++){
            minimum=min(minimum,find(nums[i]));
        }

        return minimum;
    }
};