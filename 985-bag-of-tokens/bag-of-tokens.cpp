class Solution {
public:
    int bagOfTokensScore(vector<int>& nums, int power) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1){
            if(nums[0]<=power) return 1;
            else return 0;
        } 
        int i=0;
        int j=n-1;

        int token=0;
        int maxtoken=0;
        while(i<=j){
            bool flagg=true;

            while(i<=j && power>=nums[i]){
                power=power-nums[i];
                token++;
                flagg=false;
                i++;
            }
            maxtoken=max(maxtoken,token);

            if(flagg==true && token==0) return maxtoken;
            
            if(token>=1){
                power+=nums[j];
                token--;
                j--;
            }
            else return maxtoken;
            while(i<=j && power>=nums[i]){
                token++;
                power-=nums[i];
                i++;
            }

            maxtoken=max(maxtoken,token);
        }
        return maxtoken;
    }
};