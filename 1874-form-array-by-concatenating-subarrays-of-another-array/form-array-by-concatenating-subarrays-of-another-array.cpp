class Solution {
public:
    int n;
    int m;
    bool isTrue(vector<int>&nums,vector<vector<int>>& groups,int i,int j){
        int l=0;
        int p=i;

        while(p<nums.size() && l<groups[j].size()){
            if(nums[p]!=groups[j][l]) return false;

            p++;
            l++;
        }
        if(l>=groups[j].size()) return true;
        return false;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        n=nums.size();
        m=groups.size();
        int j=0;
        int i=0;
        while(i<n){
            if(isTrue(nums,groups,i,j)){
                i+=groups[j].size();
                j++;
            }
            else i++;

            if(j>=groups.size()) break;
        }
        if(j>=groups.size()) return true;
        return false;
    }
};