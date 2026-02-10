class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>even;
            unordered_map<int,int>odd;

            for(int j=i;j<n;j++){
                if(nums[j]%2==0) even[nums[j]]++;
                else odd[nums[j]]++;

                if(even.size()==odd.size()) maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};