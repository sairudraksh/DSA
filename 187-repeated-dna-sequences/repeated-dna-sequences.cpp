class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        vector<string>v;
        if(n<10) return v;
        int j=9;
        int i=0;
        unordered_map<string,int>map;
        while(j<n){
            string str=s.substr(i,10);
            if(map[str]==1){
                v.push_back(str);
                map[str]++;
            }
            else map[str]++;
            i++;
            j++;
        }
        return v;
    }
};