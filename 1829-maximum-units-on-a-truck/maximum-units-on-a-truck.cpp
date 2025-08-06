class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& nums, int truckSize) {
        sort(nums.begin(),nums.end(),cmp);
        int n=nums.size();

        int sum=0;

        for(int i=0;i<nums.size();i++){
            if(truckSize==0) break;

            if(nums[i][0]<truckSize){
                sum+=nums[i][0]*nums[i][1];
                truckSize-=nums[i][0];
            }
            else{
                int ans=truckSize*nums[i][1];

                sum+=ans;
                break;
            }

        }
        return sum;
    }
};