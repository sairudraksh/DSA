class Solution {
public:
    bool find(vector<int>& nums,int weight,int days){
        int w=weight;
        int count=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=weight){
                weight=weight-nums[i];
            }
            else{
                count++;
                weight=w;
                weight=weight-nums[i];
            }
        }
        if(count<=days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int sum=0;
        int maxele=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxele=max(maxele,nums[i]);
        }

        int lo=maxele;
        int hi=sum;
        int ans=sum;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(find(nums,mid,days)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};