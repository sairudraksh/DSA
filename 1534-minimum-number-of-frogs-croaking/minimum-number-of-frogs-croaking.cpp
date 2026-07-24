class Solution {
public:
    int minNumberOfFrogs(string s) {
        vector<int>v1;
        vector<int>v2;
        unordered_map<char,int>map;
        for(int i=0;i<s.length();i++){
            if(s[i]=='c') v1.push_back(i);
            else if(s[i]=='k') v2.push_back(i);
            map[s[i]]++;
            if(map['c']<map['r'] ||map['c']<map['o'] || map['c']<map['a'] || map['c']<map['k']) return -1;
            if(map['r']<map['o'] ||map['r']<map['a'] || map['r']<map['k']) return -1;
            if(map['o']<map['a'] ||map['o']<map['k']) return -1;
            if(map['a']<map['k']) return -1;
            if(v2.size()>v1.size()) return -1;
        }

        for(auto x:map){
            if(x.second!=v1.size()) return -1;
        }

        vector<vector<int>>ans; 
        if(v1.size()!=v2.size()) return -1;
        for(int i=0;i<v1.size();i++){
            ans.push_back({v1[i],v2[i]});
        }
        
        int maximum=0;
        int active=1;
        for(int i=1;i<s.length();i++){
            if(s[i]=='c') active++;
            else if(s[i]=='k') active--;
            maximum=max(maximum,active);
        }
        return maximum;

    }
};