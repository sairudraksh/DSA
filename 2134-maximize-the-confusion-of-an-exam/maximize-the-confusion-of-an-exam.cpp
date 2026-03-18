class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.length();
        unordered_map<int,int>map;

        int i=0;
        int j=0;
        int maxcount=0;

        while(j<n){
            map[s[j]]++;

            while(i<j && map['T']>k && map['F']>k){
                map[s[i]]--;
                i++;
            }
            maxcount=max(maxcount,j-i+1);
            j++;
        }
        return maxcount;
    }
};