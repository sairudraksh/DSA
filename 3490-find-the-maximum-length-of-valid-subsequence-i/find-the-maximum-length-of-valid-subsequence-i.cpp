class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int maxcount=-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) count++;
        }
        maxcount=max(maxcount,count);
        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0) count++;
        }
        maxcount=max(count,maxcount);
        count=0;

        int prevans=0;
        for(int i=0;i<n;i++){
            if(i==0){
                prevans=nums[i]%2;
                count++;
            }
            else if(prevans==0){
                if(nums[i]%2!=0){
                    prevans=nums[i]%2;
                    count++;
                }
            }
            else if(prevans==1){
                if(nums[i]%2!=1){
                    prevans=nums[i]%2;
                    count++;
                }
            }
        }
        maxcount=max(count,maxcount);
        return maxcount;
    }
};