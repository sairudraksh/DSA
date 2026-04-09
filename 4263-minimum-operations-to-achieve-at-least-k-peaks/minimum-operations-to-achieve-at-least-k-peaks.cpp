class Solution {
public:
    vector<vector<int>> dp1, dp2;

    int find(vector<int>& nums,int i,int count,bool takenfirst,int &k){
        if(count>=k) return 0;
        if(i>=nums.size()) return INT_MAX;

    
        if(takenfirst){
            if(dp1[i][count] != -1) return dp1[i][count];
        } else {
            if(dp2[i][count] != -1) return dp2[i][count];
        }

        int ans;

        if(i==nums.size()-1){
            if(takenfirst){
                ans = find(nums,i+1,count,takenfirst,k);
            }
            else{
                int a=find(nums,i+2,count+1,takenfirst,k);

                if(a!=INT_MAX){
                    int num=max(nums[i-1],nums[0]);

                    int diff=num-nums[i];
                    if(diff<0) diff=0;
                    else diff+=1;

                    a+=diff;
                }
                ans = a;
            }
        }
        else if(i==0){
            int b=find(nums,i+1,count,takenfirst,k);

            int a=find(nums,i+2,count+1,true,k);

            if(a!=INT_MAX){
                int num=max(nums[nums.size()-1],nums[i+1]);

                int diff=num-nums[i];
                if(diff<0) diff=0;
                else diff+=1;

                a+=diff;
            }
            ans = min(a,b);
        }
        else{
            int b=find(nums,i+1,count,takenfirst,k);

            int a=find(nums,i+2,count+1,takenfirst,k);

            if(a!=INT_MAX){
                int num=max(nums[i-1],nums[i+1]);

                int diff=num-nums[i];
                if(diff<0) diff=0;
                else diff+=1;

                a+=diff;
            }
            ans = min(a,b);
        }

        if(takenfirst){
            dp1[i][count] = ans;
        } else {
            dp2[i][count] = ans;
        }

        return ans;
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        dp1.assign(n, vector<int>(k+1, -1));
        dp2.assign(n, vector<int>(k+1, -1));

        int a = find(nums,0,0,false,k);
        if(a==INT_MAX) return -1;
        return a;
    }
};