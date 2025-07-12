class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left=firstPlayer, right=secondPlayer;
        if(left==n-right+1) return {1,1};
        if(left>n-right+1) {
            int temp=n-left+1;
            left=n-right+1;
            right=temp;
        }
        int minRound=n, maxRound=1, nextRoundPlayersCount=(n+1)/2;
        if(right<=nextRoundPlayersCount) {
            int countLeft=left-1, midCount=right-left-1;
            for(int survivorsLeft=0; survivorsLeft<=countLeft; survivorsLeft++) {
                for(int survivorsMid=0; survivorsMid<=midCount; survivorsMid++) {
                    int pos1=survivorsLeft+1;
                    int pos2=pos1+survivorsMid+1;
                    vector<int> tempResult=earliestAndLatest(nextRoundPlayersCount,pos1,pos2);
                    minRound=min(minRound,tempResult[0]+1);
                    maxRound=max(maxRound,tempResult[1]+1);
                }
            }
        } else {
            int fightsRight=n-right+1, countLeft=left-1, midCount=fightsRight-left-1, remainMidCount=right-fightsRight-1;
            for(int survivorsLeft=0; survivorsLeft<=countLeft; survivorsLeft++) {
                for(int survivorsMid=0; survivorsMid<=midCount; survivorsMid++) {
                    int pos1=survivorsLeft+1;
                    int pos2=pos1+survivorsMid+(remainMidCount+1)/2+1;
                    vector<int> tempResult=earliestAndLatest(nextRoundPlayersCount,pos1,pos2);
                    minRound=min(minRound,tempResult[0]+1);
                    maxRound=max(maxRound,tempResult[1]+1);
                }
            }
        }
        return {minRound,maxRound};
    }
};
