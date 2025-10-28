class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);

        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }

        for(int i=n-2;i>=0;i--){
            suffix[i]=nums[i]+suffix[i+1];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(abs(prefix[i]-suffix[i])==1){
                    count++;
                }
                else if(abs(prefix[i]-suffix[i])==0){
                    count+=2;
                }
            }
        }
        return count;
    }
};