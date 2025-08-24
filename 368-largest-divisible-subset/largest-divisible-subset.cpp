class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int maxlen=1;
        int lastindex=0;

        vector<int>v(n,1);
        vector<int>previdx(n,-1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(v[i]<v[j]+1){
                        v[i]=v[j]+1;
                        previdx[i]=j;
                    }
                }
            }
            if(v[i]>maxlen){
                maxlen=v[i];
                lastindex=i;
            }
        }
        vector<int>ans;
        while(lastindex!=-1){
            ans.push_back(nums[lastindex]);
            lastindex=previdx[lastindex];
        }
        return ans;
    }
};