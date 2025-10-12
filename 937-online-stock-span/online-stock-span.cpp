class StockSpanner {
public:
    vector<int>v;
    StockSpanner() {
    }
    
    int next(int price) {
        v.push_back(price);
        int count=0;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]<=price) count++;
            else break;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */