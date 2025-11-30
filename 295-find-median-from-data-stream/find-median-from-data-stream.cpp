class MedianFinder {
public:
    priority_queue<double ,vector<double>,greater<double>>minheap;
    priority_queue<double>maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.size()==0 || maxheap.top()>num){// maxheap will keep smaller elements and min heap will keep greater elements;
            maxheap.push(num);
        }
        else minheap.push(num);

        if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(minheap.size()>maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size()){
            return (minheap.top()+maxheap.top())/2.0;
        }
        else if(maxheap.size()>minheap.size()) return maxheap.top();
        return minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */