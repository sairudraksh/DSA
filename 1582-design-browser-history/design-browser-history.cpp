class BrowserHistory {
public:
    vector<string>v;
    int i;
    BrowserHistory(string homepage) {
        i=0;

        v.push_back(homepage);
    }
    
    void visit(string url) {
        v.resize(i + 1);
        v.push_back(url);
        i++;
    }
    
    string back(int steps) {
        int k=steps;
        while(i>0 && k>0){
            i--;
            k--;
        }
        return v[i];
    }
    
    string forward(int steps) {
        int k=steps;
        while(i<v.size()-1 && k>0){
            i++;
            k--;
        }
        return v[i];
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */