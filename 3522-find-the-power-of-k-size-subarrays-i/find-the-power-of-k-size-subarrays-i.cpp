class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool>prefix(n,false);
        int count=0;

        int i=0;
        int j=0;
        vector<int>ans;
        while(j-i+1!=k+1){
            if(0==j){
                j++;
                continue;
            }
            else if(nums[j]==nums[j-1]+1){
                count++;
                prefix[j]=true;
               
            }
            j++;
        }
        j--;
        while(j<n){
            if(i==j){
                ans.push_back(nums[j]);
                i++;
                j++;
                continue;
            }
            if(count==k-1){
                ans.push_back(nums[j]);
            }
            else ans.push_back(-1);
            j++;
            i++;
            if(i<n && prefix[i]==true) count--;
            if(j<n && nums[j]==nums[j-1]+1){
                count++;
                prefix[j]=true;
            }
        }
        return ans;
    }
};