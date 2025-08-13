class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>set;
        int n=s.length();
        int count=1;
        for(int i=0;i<n;i++){
            if(set.count(s[i])){
                set.clear();
                count++;
            }
            set.insert(s[i]);
        }
        return count;
    }
};