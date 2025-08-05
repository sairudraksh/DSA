class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& nums, int Pos, int k) {
        int n=nums.size();

        vector<int>prefixSum(n);
        vector<int>indices(n);

        for(int i=0;i<n;i++){
            indices[i]=nums[i][0];
            prefixSum[i]=nums[i][1]+(i>0?prefixSum[i-1]:0);
        }
        int maximum=0;
        for(int d=0;d<=k/2;d++){
            int i=Pos-d;
            int j=Pos+(k-(2*d));

            int left=lower_bound(indices.begin(),indices.end(),i)-indices.begin();

            int right=upper_bound(indices.begin(),indices.end(),j)-indices.begin()-1;

            if(left<=right){
                int ans=prefixSum[right]-(left>0?prefixSum[left-1]:0);
                maximum=max(maximum,ans);
            }

            i=Pos-(k-(2*d));
            j=Pos+d;

            left=lower_bound(indices.begin(),indices.end(),i)-indices.begin();

            right=upper_bound(indices.begin(),indices.end(),j)-indices.begin()-1;
            
            if(left<=right){
                int ans=prefixSum[right]-(left>0?prefixSum[left-1]:0);
                maximum=max(maximum,ans);
            }

        }

        return maximum;
    }
};