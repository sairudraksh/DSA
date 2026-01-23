class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>map;
        vector<string>v;
        string s="";
        for(int i=0;i<s1.length();i++){
            if(s1[i]==' '){
                map[s]++;
                s="";
                continue;
            }
            s+=s1[i];
        }
        if(s.length()>0) map[s]++;
        s="";
        for(int i=0;i<s2.length();i++){
            if(s2[i]==' '){
                map[s]++;
                s="";
                continue;
            }
            s+=s2[i];
        }
        if(s.length()>0) map[s]++;
        for(auto x:map){
            if(x.second==1){
                v.push_back(x.first);
            }
        }
        return v;
    }
};