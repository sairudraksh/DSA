class Solution {
public:
    vector<bool>visited;
    set<string>st;
    void find(string &s,string &str){
        

        for(int i=0;i<s.length();i++){
            if (i>0 && s[i]==s[i - 1] && !visited[i-1]) continue;
            if(visited[i]) continue;
            else{
                visited[i]=true;
                str+=s[i];
                st.insert(str);
                find(s,str);
                str.pop_back();
                visited[i]=false;
            }
        }
      
    }
    int numTilePossibilities(string s) {
        string str="";
        sort(s.begin(),s.end());
        visited.resize(s.length()+1,false);
        find(s,str);
        return st.size();
    }
};