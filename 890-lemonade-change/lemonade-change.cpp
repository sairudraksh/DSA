class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int five=0;
        int ten=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==5){
                five++;
            }
            else if(nums[i]==10){
                if(five==0) return false;
                else{
                    ten++;
                    five--;
                }
            }
            else{
                if(ten!=0 && five!=0){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }
                else return false;
            }
        }
        return true;
    }
};