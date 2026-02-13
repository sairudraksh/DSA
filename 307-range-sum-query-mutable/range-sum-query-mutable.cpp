class NumArray {
public:
    vector<int>arr;
    vector<int>st;
    int n;
    void buildTree(int i,int lo,int hi){
        if(lo==hi){
            st[i]=arr[lo];
            return;
        }
        int mid=lo+(hi-lo)/2;
        buildTree(2*i+1,lo,mid);
        buildTree(2*i+2,mid+1,hi);
        st[i]=st[2*i+1]+st[2*i+2];
    }
    NumArray(vector<int>& nums){
        n=nums.size();
        arr=nums;
        st.resize(4*n);
        buildTree(0,0,n-1);
    }
    
    void update(int index, int val) {
        updateValue(0,0,n-1,index,val);
    }
    void updateValue(int i,int lo,int hi,int &index,int &val){
        if(lo==hi){
            st[i]=val;
            return;
        }
        int mid=lo+(hi-lo)/2;

        if(mid>=index) updateValue(2*i+1,lo,mid,index,val);
        else updateValue(2*i+2,mid+1,hi,index,val);

        st[i]=st[2*i+1]+st[2*i+2];
    }
    int getSum(int i,int lo,int hi,int left,int right){
        if(lo>right || hi<left) return 0;
        if(lo>=left && hi<=right) return st[i];

        int mid=lo+(hi-lo)/2;
        int a=getSum(2*i+1,lo,mid,left,right);
        int b=getSum(2*i+2,mid+1,hi,left,right);

        return a+b;
    }
    int sumRange(int left, int right) {
        return getSum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */