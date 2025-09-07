class Solution {
public:
    int minOperations(string s) {
        priority_queue<char,vector<char>,greater<char>>pq;
        for(int i=0;i<s.length();i++){
            if(s[i]!='a') pq.push(s[i]);
        }

        long long count=0;
        long long prevfreq=0;
        while(!pq.empty() && pq.top()!='a'){
            char x=pq.top();
            long long freq=0;
            freq+=prevfreq;
            while(!pq.empty() && pq.top()==x){
                pq.pop();
                freq++;
            }
            if(!pq.empty()){
                count=count+((int)pq.top()-(int)x);
                prevfreq=freq;
            }
            else{
                count+=(int)'z'+1-(int)pq.top();
                prevfreq=0;
            }
        }
        return count;
    }
};