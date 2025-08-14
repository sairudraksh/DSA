class Solution {
public:
    string largestGoodInteger(string nums) {
        int n=nums.length();
        string s="";
        int count=1;
        string ans="";
        if(nums.length()<3) return "";
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
                s+=nums[i];
            }
            else{
                s="";
                count=1;
            }
            if(count==3){
                s+=nums[i];
                ans=max(ans,s);
                s="";
                count=1;
            }
        }
        return ans;
    }
};