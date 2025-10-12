class StockSpanner {
public:
    stack<pair<int,int>>ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        if(ans.size()==0){
            ans.push({price,1});
        }
        else{
            while(ans.size()>0 && ans.top().first<=price){
                count+=ans.top().second;
                ans.pop();
            }
           ans.push({price,count});
        }
        
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */