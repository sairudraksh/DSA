class Solution {
public:
    int dp[1001][1002][4][3];
    int find(vector<int>&ratings,int i,int count,int prev,bool incr){
        if(count==3) return 1;
        if(i>=ratings.size()) return 0;

        if(dp[i][prev+1][count][incr]!=-1) return dp[i][prev+1][count][incr];

        int skip=find(ratings,i+1,count,prev,incr);
        int take=0;
        if(prev==-1){
            take=find(ratings,i+1,count+1,i,incr);
        }
        else if(count==1){
            if(ratings[i]>ratings[prev]){
                take=find(ratings,i+1,count+1,i,true);
            }
            else if(ratings[i]<ratings[prev]){
                take=find(ratings,i+1,count+1,i,false);
            }
        }
        else{
            if(incr==true && ratings[i]>ratings[prev]){
                take=find(ratings,i+1,count+1,i,true);
            }
            else if(incr==false && ratings[i]<ratings[prev]){
                take=find(ratings,i+1,count+1,i,false);
            }
        }
        return dp[i][prev+1][count][incr]=skip+take;
    }
    int numTeams(vector<int>& rating) {
        memset(dp,-1,sizeof(dp));
        return find(rating,0,0,-1,0);
    }
};