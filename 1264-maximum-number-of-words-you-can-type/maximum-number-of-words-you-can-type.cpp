class Solution {
public:
    int canBeTypedWords(string s, string brokenLetters) {
        unordered_map<char,int>map;
        for(int i=0;i<brokenLetters.length();i++){
            map[brokenLetters[i]]++;
        }
        bool flagg=false;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(map.find(s[i])!=map.end()){
                flagg=true;
            }
            if(s[i]==' '){
                if(flagg==false){
                    count++;
                }
                flagg=false;
            }
        }
        if(flagg==false) count++;
        return count;
    }
};