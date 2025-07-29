class MedianFinder {
public:
    priority_queue<int ,vector<int>,greater<int>>minHeap;
    priority_queue<int>maxHeap;
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(maxHeap.size()==0 || num<maxHeap.top()){
            maxHeap.push(num);
        }
        else minHeap.push(num);

        if(minHeap.size()+1<maxHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        else if(minHeap.size()>maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            double ans=(maxHeap.top()+minHeap.top())/2.0;
            return ans;
        }
        else if(minHeap.size()<maxHeap.size()) return maxHeap.top();
        else return minHeap.top();
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */