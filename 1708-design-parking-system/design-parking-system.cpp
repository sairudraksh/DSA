class ParkingSystem {
public:
    vector<int>v;
    ParkingSystem(int big, int medium, int small) {
        v.push_back(big);
        v.push_back(medium);
        v.push_back(small);
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(v[0]>=1){
                v[0]--;
                return true;
            }
            else return false;
        }
        if(carType==2){
            if(v[1]>=1){
                v[1]--;
                return true;
            }
            else return false;
        }
        if(carType==3){
            if(v[2]>=1){
                v[2]--;
                return true;
            }
            else return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */