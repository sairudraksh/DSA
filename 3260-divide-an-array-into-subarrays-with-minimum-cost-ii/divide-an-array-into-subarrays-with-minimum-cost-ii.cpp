class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> P;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();

        set<P>kMinimum;
        set<P>remaining;

        int i=1;
        ll sum=0;

        while(i-dist<1){
            sum+=nums[i];
            kMinimum.insert({nums[i],i});
            if(kMinimum.size()>k-1){
                P temp=*kMinimum.rbegin();
                sum-=temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }
            i++;
        }
        ll result=LLONG_MAX;
        while(i<n){
            kMinimum.insert({nums[i],i});
            sum+=nums[i];
            if(kMinimum.size()>k-1){
                P temp=*kMinimum.rbegin();
                sum-=temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }
            result=min(result,sum);
            P remove={nums[i-dist],i-dist};

            if(kMinimum.count(remove)){
                kMinimum.erase(remove);
                sum-=remove.first;

                if(!remaining.empty()){
                    P temp=*remaining.begin();
                    kMinimum.insert(temp);
                    sum+=temp.first;
                    remaining.erase(temp);
                }
            }
            else remaining.erase(remove);
            i++;
        }
        return nums[0]+result;
    }
};