class Solution {
public:
    int bfs(vector<vector<int>>& routes,unordered_map<int,vector<int>>&map,vector<int>&v,int &target){
        queue<int>q;
        vector<int>visited;
        visited.resize(routes.size()+1,0);
        for(int i=0;i<v.size();i++){
            q.push(v[i]);
            visited[v[i]]=1;
        }
       
        int count=1;

        while(q.size()>0){
            int size=q.size();

            for(int l=0;l<size;l++){
                int i=q.front();
                q.pop();

                vector<int>v=routes[i];

                for(int j=0;j<v.size();j++){
                    if(v[j]==target) return count;

                    int num=v[j];

                    vector<int>v2=map[num];
                    for(int k=0;k<v2.size();k++){
                        if(!visited[v2[k]]){
                            q.push(v2[k]);
                            visited[v2[k]]=1;
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>map;
        int n=routes.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].size();j++){
                int num=routes[i][j];
                map[num].push_back(i);
            }
        }
        vector<int>v;
        if(source==target){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].size();j++){
                if(routes[i][j]==source){
                    v.push_back(i);
                    break;
                }
            }
        }
        int minimum=INT_MAX;

        
         minimum=min(minimum,bfs(routes,map,v,target));
      
        return minimum;
    }
};