//[1,2,1,1,2,1,2]// like for example we want for this so %2=0 will be when all are even 
//2  %2=0 will also be when all are odd
// when %2=1 means they are alternative 
// so here remainder of all are same in 3 cases means these can be all possible types

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int maxcount=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) count++;
        }
        maxcount=max(count,maxcount);
        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0) count++;
        }
        maxcount=max(maxcount,count);
        count=0;
        int preval;
        for(int i=0;i<n;i++){
            if(i==0){
                preval=nums[0]%2;
                count++;
            }
            else if(preval==0){
                if(nums[i]%2!=0){
                    count++;
                    preval=nums[i]%2;
                }
            }
            else if(preval==1){
                if(nums[i]%2==0){
                    count++;
                    preval=nums[i]%2;
                }
            }
        }
        maxcount=max(maxcount,count);
        return maxcount;
    }
};