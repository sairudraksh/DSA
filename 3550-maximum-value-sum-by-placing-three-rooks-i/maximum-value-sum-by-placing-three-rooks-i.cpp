class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<pair<int,int>>>v(n);
        for(int i=0;i<n;i++){
            vector<pair<int,int>>p;


            for(int j=0;j<m;j++){
                p.push_back({board[i][j],j});
            }

            sort(p.rbegin(),p.rend());

            for(int k=0;k<3;k++){
                v[i].push_back(p[k]);
            }
        }
        long long ans=LLONG_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){

                    for(auto a:v[i]){
                        for(auto b:v[j]){
                            for(auto c:v[k]){
                                if(a.second!=b.second && b.second!=c.second && a.second!=c.second){
                                    long long num=1LL*a.first+b.first+c.first;
                                    ans=max(ans,num);
                                }
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};