class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()!=1 && pq.size()!=0){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x>y){
                x=x-y;
                pq.push(x);
            }
            else if(y>x){
                y=y-x;
                pq.push(y);
            }
        }
        if(pq.size()==0) return 0;
        else return pq.top();
    }
};