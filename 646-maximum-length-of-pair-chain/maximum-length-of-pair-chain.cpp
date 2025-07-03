class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if(n==0)return 0;

        sort(pairs.begin(),pairs.end(),cmp);

        int count = 1;
        vector<vector<int>>ans;
        ans.push_back(pairs[0]);

        for(int i=1;i<n;i++) {
            vector<int>&last=ans.back();
            if(pairs[i][0]>last[1]) {
                ans.push_back(pairs[i]);
                count++;
            }
        }
        return count;
    }
};
