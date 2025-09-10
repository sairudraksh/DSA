class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>st;

        for(auto friends : friendships){
            int u=friends[0]-1;
            int v=friends[1]-1;

            unordered_set<int>set;

            for(int i=0;i<languages[u].size();i++){
                set.insert(languages[u][i]);
            }
            bool cantalk=false;
            for(int i=0;i<languages[v].size();i++){
                if(set.find(languages[v][i])!=set.end()){
                    cantalk=true;
                    break;
                }
            }

            if(!cantalk){
                st.insert(u);
                st.insert(v);
            }
        }

        int maximum=0;
        unordered_map<int,int>map;
        for(auto &x: st){
            vector<int>v=languages[x];
            for(int i=0;i<v.size();i++){
                map[v[i]]++;
            }
        }
        for(auto x:map){
            if(x.second>maximum) maximum=x.second;
        }
        return st.size()-maximum;
    }
};