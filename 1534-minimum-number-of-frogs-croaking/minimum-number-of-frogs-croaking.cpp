class Solution {
public:
    int minNumberOfFrogs(string s) {

        unordered_map<char,int>map;
        for(int i=0;i<s.length();i++){
    
            map[s[i]]++;
            if(map['c']<map['r'] ||map['c']<map['o'] || map['c']<map['a'] || map['c']<map['k']) return -1;
            if(map['r']<map['o'] ||map['r']<map['a'] || map['r']<map['k']) return -1;
            if(map['o']<map['a'] ||map['o']<map['k']) return -1;
            if(map['a']<map['k']) return -1;
    
        }


        int prev=-1;
        for(auto x:map){
            if(prev==-1) prev=x.second;
            else if(prev!=x.second) return -1;
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