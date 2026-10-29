class Solution {
public:
    int maxScore(vector<int>& nums, int num) {
        int n=nums.size();
        int minsum=0;
        int k=n-num;
        for(int i=0;i<k;i++){
            minsum+=nums[i];
        }
        int i=0;
        int j=k;
        int currsum=minsum;
        while(j<n){
            currsum+=nums[j];
            currsum-=nums[i];
            j++;
            i++;

            if(currsum<minsum) minsum=currsum;
        }
        int total=0;

        for(int i=0;i<n;i++){
            total+=nums[i];
        }

        return total-minsum;
    }
};