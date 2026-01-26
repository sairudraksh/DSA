class Solution {
public:
    vector<bool>visited;
    int find(string &s,string &str){
        int count=0;

        for(int i=0;i<s.length();i++){
            if (i>0 && s[i]==s[i - 1] && !visited[i-1]) continue;// we skip as in later calls first a might be taken and we will get duplicate so to avioid this we  will always take first A
            if(visited[i]) continue;
            else{
                visited[i]=true;
                str+=s[i];
                count++;
                count+=find(s,str);
                str.pop_back();
                visited[i]=false;
            }
        }
        return count;
    }
    int numTilePossibilities(string s) {
        string str="";
        sort(s.begin(),s.end());
        visited.resize(s.length()+1,false);
        return find(s,str);
    }
};