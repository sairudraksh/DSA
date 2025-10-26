class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int n=nums.size();
        int fivecount=0;
        int tencount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==5){
                fivecount++;
            }
            else if(nums[i]==10){
                if(fivecount==0) return false;
                tencount++;
                fivecount--;
            }
            else{
                if(tencount!=0 && fivecount!=0){
                    fivecount--;
                    tencount--;
                }
                else if(fivecount>=3){
                    fivecount-=3;
                }
                else return false;
            }
        }
        return true;
    }
};