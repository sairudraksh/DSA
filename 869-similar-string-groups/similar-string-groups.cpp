class Solution {
public:
    bool isAnagram(string &s1,string &s2){
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) count++;
            if(count>2) return false;
        }
        return (count==2 || count==0);
    }
    void bfs(vector<int>&visited,int idx,vector<string>&strs,unordered_map<int,vector<int>>&map){
        visited[idx]=1;
        queue<int>q;
        q.push(idx);

        while(q.size()>0){
            int i=q.front();
            string s=strs[i];
            q.pop();
            auto v=map[i];
            for(int k=0;k<v.size();k++){
                if(visited[v[k]]==0){
                    q.push(v[k]);
                    visited[v[k]]=1;
                }
            }
        }
        return;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<int>visited;
        visited.resize(n+1,0);
        int count=0;
        unordered_map<int,vector<int>>map;
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs.size();j++){
                if(i==j) continue;
                else if(isAnagram(strs[i],strs[j])){
                    map[i].push_back(j);
                }
            }
        }

        for(int i=0;i<strs.size();i++){
            if(visited[i]==0){
                bfs(visited,i,strs,map);
                count++;
            }
        }
        return count;
    }
};