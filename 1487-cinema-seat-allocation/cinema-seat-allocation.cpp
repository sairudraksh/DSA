class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        int i=0;
        int curr=0;
        int ans=0;
        sort(nums.begin(),nums.end());
        while(i<nums.size()){
            curr++;
            int count1=1;
            int count2=1;
            int count3=1;

            bool found=false;

            while(i<nums.size() && nums[i][0]==curr){
                int seat=nums[i][1];

                if(seat==2||seat==3||seat==4||seat==5) count1=0;
                if(seat==4||seat==5||seat==6||seat==7) count2=0;
                if(seat==6||seat==7||seat==8||seat==9) count3=0;

                i++;
                found=true;

            }
            if(found==false){
                ans+=2;
                continue;
            }
            if(count1==1 && count2==1 && count3==1){
                ans+=2;
            }
            else if(count1==1 || count3==1 || count2==1) ans+=1;
        }
        
        int num=n-curr;
        ans+=num*2;

        return ans;
    }
};