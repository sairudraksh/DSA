class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        if(n<=2) return false;
        int Acount=0;
        int Bcount=0;

        for(int i=1;i<n-1;i++){
            int prev=i-1;
            int curr=i;
            int next=i+1;
            
            if(colors[prev]=='A' && colors[curr]=='A' && colors[next]=='A') Acount++;
            else if(colors[prev]=='B' && colors[curr]=='B' && colors[next]=='B') Bcount++;
        }
        if(Acount>Bcount) return true;
        else return false;
    }
};