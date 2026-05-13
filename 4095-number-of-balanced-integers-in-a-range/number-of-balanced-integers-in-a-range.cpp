class Solution {
public:
    vector<long long>v;
    long long dp[17][2][145][145];
    long long find(long long pos,long long tigh,long long sum1,long long sum2,int &m){
        if(pos>=m){
            if(sum1==sum2 && sum1+sum2!=0) return 1;
            return 0;

        }
        if(tigh==0 && dp[pos][tigh][sum1][sum2]!=-1) return dp[pos][tigh][sum1][sum2];
        long long limit=0;

        if(tigh==1){
            limit=v[pos];
        }
        else limit=9;
        long long sum=0;
        for(int i=0;i<=limit;i++){
            int newtigh;

            if(tigh==1 && i==v[pos]){
                newtigh=1;
            }
            else newtigh=0;


            if(pos%2==0) sum+=find(pos+1,newtigh,sum1+i,sum2,m);
            else sum+=find(pos+1,newtigh,sum1,sum2+i,m);
        }
        if(tigh==0){
            return dp[pos][tigh][sum1][sum2]=sum;
        }
        else return sum;
    }   
    long long solve(long long x){
        if(x<10) return 0;
        v.clear();
        for(int i=0;i<17;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<145;k++){
                    for(int l=0;l<145;l++){
                        dp[i][j][k][l]=-1;
                    }
                }
            }
        }
        string s=to_string(x);
        for(int i=0;i<s.length();i++){
            v.push_back(s[i]-'0');
        }
        int m=s.length();
        return find(0,1,0,0,m);   
    }
    long long countBalanced(long long low, long long high) {
       
        return solve(high) - solve(low - 1);
    }
};