class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& nums) {
        int n=fruits.size();
        int count=0;
        for(int i=0;i<n;i++){
            int x=fruits[i];
            bool flagg=false;
            for(int j=0;j<n;j++){
                if(nums[j]!=INT_MIN && nums[j]>=x){
                    nums[j]=INT_MIN;
                    flagg=true;
                    break;
                }
            }
            if(flagg==false) count++;
        }

        return count;
    }
};