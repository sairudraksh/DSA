class Bank {
public:
    vector<long long>v;
    int n;
    Bank(vector<long long>& balance) {
        v=balance;
        n=balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        int idx1=account1-1;
        int idx2=account2-1;

        if(idx1<0 || idx1>=n || idx2<0 || idx2>=n || money>v[idx1]) return false;
        v[idx2]=v[idx2]+money;
        v[idx1]-=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        int idx=account-1;
        if(idx<0 || idx>=n) return false;
        v[idx]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        int idx=account-1;
        if(idx<0 || idx>=n) return false;
        if(money>v[idx]) return false;
        v[idx]-=money;
        return true;
    }
};
/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */