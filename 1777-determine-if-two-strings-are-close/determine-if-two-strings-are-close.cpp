class Solution {
public:
    bool closeStrings(string s1, string s2) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        if(s1.length()!=s2.length()) return false;
        int n=s1.length();
        for(int i=0;i<s1.length();i++){
            map1[s1[i]]++;
        }
        for(int i=0;i<s2.length();i++){
            map2[s2[i]]++;
        }
        vector<int>v1(n,-1);
        vector<int>v2(n,-1);
        int i=0;
        for(auto &x:map1){
            if(map2.find(x.first)==map2.end()) return false;
            v1[i]=x.second;
            i++;
        }
        i=0;
        for(auto &x:map2){
            if(map1.find(x.first)==map1.end()) return false;
            v2[i]=x.second;
            i++;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(int i=0;i<n;i++){
            if(v1[i]!=v2[i]) return false;
            else{}
        }
        return true;
    }
};