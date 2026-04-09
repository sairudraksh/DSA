class Solution {
public:
    bool istrue(unordered_map<char,int>&map1, unordered_map<char,int>&map2){
        for(auto x:map1){
            if(map2.find(x.first)!=map2.end()) return false;
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        vector<unordered_map<char,int>>v;

        for(int i=0;i<words.size();i++){
            string s=words[i];
            unordered_map<char,int>map;
            for(int i=0;i<s.length();i++){
                map[s[i]]++;
            }
            v.push_back(map);
        }

        int maximum=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(istrue(v[i],v[j])){
                    int len=words[i].length()*words[j].length();
                    maximum=max(maximum,len);
                }
            }
        }
        return maximum;
    }
};