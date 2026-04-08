class Solution {
public:
    vector<int> movesToStamp(string stamps, string target){
        vector<int>res;
        int totalStars=0;

        int n=target.size();
        int m=stamps.size();
        vector<int>visited;
        visited.resize(n+1,0);
        while(totalStars<n){
            bool match=false;
            for(int i=0;i<=n-m;i++){
                if(visited[i]==1) continue;

                bool found=true;
                int noOfStars=0;

                for(int j=0;j<m;j++){
                    if(target[i+j]=='*'){
                        noOfStars++;
                    }
                    else if(target[i+j]!=stamps[j]){
                        found=false;
                        break;
                    }
                }
                
                if(found==true && noOfStars<m){
                    match=true;
                    visited[i]=1;
                    res.push_back(i);

                    for(int j=0;j<m;j++){
                        if(target[i+j]=='*'){
                            continue;
                        }
                        else{
                            target[i+j]='*';
                            totalStars++;
                        }
                    }
                }
            }
            if(match==false) return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};