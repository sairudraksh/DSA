class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }   
        vector<int>ans;
        for(auto &x:mp){
            vector<int>v=x.second;
            if(x.first%2==0){
                reverse(v.begin(),v.end());
            }
            for(int i=0;i<v.size();i++){
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};