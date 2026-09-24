class Solution {
public:
    int n;
    bool isTrue(int num,int target){
        int sum=0;

        while(num>0){
            int x=num%10;
            sum+=x;
            num=num/10;
        }
        return sum==target;
    }
    int smallestIndex(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<n;i++){
            if(isTrue(nums[i],i)) return i;
        }

        return -1;
    }
};