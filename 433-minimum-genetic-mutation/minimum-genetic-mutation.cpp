class Solution {
public:
    bool isCompatible(string &s,string &str){
        int count=0;
        for(int i=0;i<8;i++){
            if(s[i]!=str[i]){
                count++;
            }
            if(count>=2) return false;
        }
        if(count>=2) return false;
        return true;
    }
    int find(string st,string end,vector<string>& bank){
        int n=bank.size();
        if(st==end) return 0;
        queue<string>q;
        q.push(st);
        vector<int>visited;
        visited.resize(bank.size()+1,0);
        int curr=0;
        while(q.size()>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                string s=q.front();
                q.pop();
                if(s==end) return curr;
                for(int j=0;j<bank.size();j++){
                    if(isCompatible(s,bank[j])){
                        if(visited[j]==0){
                            visited[j]=1;
                            q.push(bank[j]);
                        }
                    }
                }
            }
            curr++;
        }
        return -1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        return find(startGene,endGene,bank);
    }
};