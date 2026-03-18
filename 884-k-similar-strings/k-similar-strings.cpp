class Solution {
public:
    unordered_map<string,int>map;
    int find(string &s1,string &s2,int i){
        if(s1==s2) return 0;
        if(i>=s1.length()) return INT_MAX;
        if(map.find(s1)!=map.end()) return map[s1];
        while(i<s1.length() && s1[i]==s2[i]) i++;
        int minimum=INT_MAX;
        for(int j=i+1;j<s1.length();j++){
            if(s1[j]==s2[j]) continue;
            if(s2[i]==s1[j] && s1[j]!=s2[j]){
                swap(s1[i],s1[j]);

                int a=find(s1,s2,i+1);
                if(a!=INT_MAX){
                    a+=1;
                }

                minimum=min(minimum,a);

                swap(s1[i],s1[j]);
            }
        }
        return map[s1]=minimum;
    }

    int kSimilarity(string s1, string s2) {
        return find(s1,s2,0);
    }
};