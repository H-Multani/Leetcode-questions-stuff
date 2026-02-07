class RideSharingSystem {
public:

// queue for rider, and queue bana do for driver
    queue<int> driver;
    queue<int> rider;
    RideSharingSystem() {
        // dono ko clear kardo
        rider=queue<int>();
        driver=queue<int>();
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        // front wale pop kardo nikal kar

        if(!rider.empty() && !driver.empty()){
            // dono empty nai hai toh ans nikal kar bhej do
            int val1=rider.front();
            rider.pop();
            int val2=driver.front();
            driver.pop();

            return {val2,val1};
        }

        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        // rider wale q me iterate karke remove kardo

        int n=rider.size();

        while(n--){
            int val=rider.front();
            rider.pop();

            if(val==riderId){
                // means yehi remove karna tha kar diya remove
            }
            else{
                // means ye wala remove nai karna tha, vapas daal do q me
                rider.push(val);
            }
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */