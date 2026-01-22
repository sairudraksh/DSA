class Solution {
public:
    unordered_map<string,int>map;
    bool find(string s1,string s2){
        int n=s1.length();
        if(s1==s2) return true;
        if(s1.length()!=s2.length()) return false;
        string s=s1+"_"+s2;
        if(map.find(s)!=map.end()) return map[s];
        bool found=false;
        for(int i=1;i<s1.length();i++){
            bool swapped=find(s1.substr(0,i),s2.substr(n-i,i)) && find(s1.substr(i,n-i),s2.substr(0,n-i));

            if(swapped){
                found=true;
                break;
            }

            bool notSwapped=find(s1.substr(0,i),s2.substr(0,i)) && find(s1.substr(i,n-i),s2.substr(i,n-i));

            if(notSwapped){
                found=true;
                break;
            }
        }
        return map[s]=found;
    }
    bool isScramble(string s1, string s2){
        map.clear();
        return find(s1,s2);
    }
};