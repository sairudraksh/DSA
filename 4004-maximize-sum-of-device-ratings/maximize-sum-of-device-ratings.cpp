class Solution {
public:
    long long maxRatings(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();


        if(m==1){
            long long sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i][0];
            }
            return sum;
        }


        for(int i=0;i<n;i++){
            sort(nums[i].begin(),nums[i].end());
        }

        long long minimumSecond=LLONG_MAX;
        long long minimumFirst=LLONG_MAX;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(nums[i][0]<minimumFirst){
                minimumFirst=nums[i][0];
            }
            if(nums[i][1]<minimumSecond){
                minimumSecond=nums[i][1];
            }

            sum+=nums[i][1];
        }

        return (sum-minimumSecond)+minimumFirst;

    }
};