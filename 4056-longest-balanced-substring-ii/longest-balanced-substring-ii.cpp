class Solution {
public:
    int n;
    int find(string s,char ch1,char ch2){
        unordered_map<int,int>map;
        int countch1=0;
        int countch2=0;
        int maxcount=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=ch1 &&  s[i]!=ch2){
                map.clear();
                countch1=0;
                countch2=0;
                continue;
            }

            if(s[i]==ch1) countch1++;
            if(s[i]==ch2) countch2++;

            if(countch1==countch2){
                maxcount=max(maxcount,countch1+countch2);
            }

            int diff=countch1-countch2;

            if(map.count(diff)){
                maxcount=max(maxcount,i-map[diff]);
            }
            else map[diff]=i;
        }
        return maxcount;
    }
    int longestBalanced(string s) {
        n=s.length();
        int count=1;
        int maxcount=0;

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                maxcount=max(maxcount,count);
                count=1;
            }
        }
        maxcount=max(maxcount,count);
        
        maxcount=max(maxcount,find(s,'a','b'));
        maxcount=max(maxcount,find(s,'a','c'));
        maxcount=max(maxcount,find(s,'b','c'));

        unordered_map<string,int>map;
        int count1=0;
        int count2=0;
        int count3=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                count1++;
            }
            if(s[i]=='b'){
                count2++;
            }
            if(s[i]=='c'){
                count3++;
            }

            if(count1==count2 && count2==count3){
                maxcount=max(maxcount,count1+count2+count3);
            }

            int diffA=count1-count2;
            int diffB=count1-count3;
            string key=to_string(diffA)+"_"+to_string(diffB);
            if(map.count(key)){
                maxcount=max(maxcount,i-map[key]);
            }
            else{
                map[key]=i;
            }
        }
        return maxcount;
    }
};