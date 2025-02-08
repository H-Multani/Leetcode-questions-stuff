class NumberContainers {
    // index can be 10^9, toh vector banana bad idea MLE de dega, toh map bana
    // lo best

    unordered_map<long long, long long> arr;
    // stores <index,element>

    // okay toh TLE de raha hai, toh ab smallest index bhi store karna padega
    // element ka, toh ek aur map bana do, usme set rakhenge that will store all
    // indexes of elements
    unordered_map<int, set<int>> idx;
    // stores <value, vo value konse konse indexes par hai in order>
public:
    NumberContainers() {
        // kuch nai h yaha karne ke liya
    }

    void change(int index, int number) {
        // iss index par ye number chadha do, agar iss idx par already number
        // tha toh update kardo, vahi kia hai

        // ab iss idx par jo purana value tha, usko remove karo pehle toh idx
        // wale map se,since uss idx par new value aane wali hai toh purani
        // value ke set me vo idx nai hona chahiye

        // first chk if the old value exist or not
        if (arr.find(index) != arr.end()) {
            // we here means ki index par purani koi value hai, toh sbse pehle
            // vo value ke set se current index ko alag karo(since iss index par
            // new value aane wali hai ab )
            int oldvalue = arr[index];

            // purani value ke set me jao, idx[oldvalue], ab iss set se erase
            // krdo current index ko
            idx[oldvalue].erase(index);
        }

        // new value ke set me current index add kardo
        idx[number].insert(index);

        // update in the map
        arr[index] = number;
    }

    int find(int number) {
        // ab iterate ka need hi nai hai, set stores in sorted order

        // agar uss number ka set khali hai toh -1 return kardo nai toh
        // beginning par jo idx hai vahi smallest idx hoga vahi return kardena
        if(!idx[number].empty()){
            // means set not empty, beginning wala element return krdo
            return *idx[number].begin();
        }

        // we here means set khali hai return -1
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */