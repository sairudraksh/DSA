class Solution {
public:
    string predictPartyVictory(string s) {
        int n=s.length();

        queue<int>pq;
        queue<int>r;
        queue<int>d;

        for(int i=0;i<n;i++){
            pq.push(i);
            if(s[i]=='R') r.push(i);
            else d.push(i);
        }

        while(pq.size()>1){
            if(s[pq.front()]=='X') pq.pop();
            else if(s[pq.front()]=='R'){
                if(d.size()==0) return "Radiant";
                s[d.front()]='X';
                d.pop();
                pq.push(pq.front());
                pq.pop();
                r.push(r.front());
                r.pop();
            }
            else{
                if(r.size()==0) return "Dire";
                s[r.front()]='X';
                r.pop();
                pq.push(pq.front());
                pq.pop();
                d.push(d.front());
                d.pop();
            }
        }
        if(s[pq.front()]=='R') return "Radiant";
        else return "Dire";
    }
};