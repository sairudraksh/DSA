class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>odd1;
        unordered_map<char,int>even1;
        unordered_map<char,int>odd2;
        unordered_map<char,int>even2;


        for(int i=0;i<s1.length();i++){
            if(i%2==0){
                even1[s1[i]]++;
            }
            else odd1[s1[i]]++;
        }

        for(int i=0;i<s2.length();i++){
            if(i%2==0){
                even2[s2[i]]++;
            }
            else odd2[s2[i]]++;
        }

        for(auto x:odd1){
            if(odd2.find(x.first)!=odd2.end() && odd2[x.first]==x.second){
                continue;
            }
            else return false;
        }
        for(auto x:even1){
            if(even2.find(x.first)!=even2.end() && even2[x.first]==x.second){
                continue;
            }
            else return false;
        }
        return true;
    }
};