class Solution {
public:
    unordered_map<string,int>map;
    vector<string>finalans;
    void find(string &str,vector<string>& wordDict,int i,int j,string &s){
        if(j>=str.length()) return;
        string s1=str.substr(i,j-i+1);

        if(map.find(s1)!=map.end()){
            string old=s;
            if(!s.empty()) s+=" ";
            s+=s1;
            if(j==str.length()-1){
                finalans.push_back(s);
                return;
            }
            find(str,wordDict,j+1,j+1,s);
            s=old;
        }
        find(str,wordDict,i,j+1,s);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++){
            map[wordDict[i]]++;
        }
        string str="";
        find(s,wordDict,0,0,str);
        return finalans;
    }
};