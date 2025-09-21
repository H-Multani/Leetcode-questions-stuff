class MovieRentingSystem {
public:
    typedef pair<int, int> p;

    // map bana lo which stores movies to <price,shop> ka pair, ie
    // movie->set<{price,shop}>
    // this map stores the available movies
    unordered_map<int, set<p>> available;

    // similar map storing movie->set<{shop,price}>, ye in general iteration ke
    // liye bas
    unordered_map<int, set<p>> movitoshop;

    // similar set storing tuples of {price,shop,movie}, ye store karega the
    // movies which are currently rented
    set<tuple<int, int, int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // initially nothing rented toh dont touch that

        // iterate over entries fill the other 2 maps
        for (auto it : entries) {
            int shop = it[0];
            int movie = it[1];
            int price = it[2];

            // available me daal do
            available[movie].insert({price, shop});
            // insertion-> O(logn)
            // movitoshop me daal do
            movitoshop[movie].insert({shop, price});
            // insertion-> O(logn)
        }
    }
    
    // overall T.C-> O(const)
    vector<int> search(int movie) {
        // ezpz, available hai toh map me jaa kar, iss movie ke top ke 5 bande
        // nikal lo cheapest wale
        vector<int> ans;
        int cnt = 0;

        // agar available me ye movie hai toh bhej dena
        if (available.count(movie)) { // O(1), searching

            for (auto it : available[movie]) { // O(5)
                int shop = it.second;

                // ye shop ans me daal do
                ans.push_back(shop);
                // increase cnt
                cnt++;

                // agar cnt >5 aaya toh rok dena
                if (cnt >= 5)
                    break;
            }
        }

        return ans;
    }

    void rent(int shop, int movie) {
        // pehle nikalo ye konsi wali movie hai kitne price ki

        // iss movie ko rakhne wale sab bando ko nikalo
        // auto it = movitoshop[movie];

        // iss set me lower bound laga dena, to get cheapest banda with same
        // shop and same movie
        // auto it2 = it.lower_bound({shop, INT_MIN});
        // new way to use lower bound, gives smallest banda with value>=shop

        // dono kaam ek sath kardo, since alag alag karne se TLE aara
        auto it2 = movitoshop[movie].lower_bound({shop, INT_MIN});
        // O(logn) for checking

        // price nikal lo isse ab
        int price = it2->second;

        // since ab rent karre hai toh available se hata dena, since its no
        // longer available
        available[movie].erase({price, shop});
        // O(logn) for erasing

        // and also rented wale map me daal dena
        rented.insert({price, shop, movie});
        // O(logn) for isnert
    }

    void drop(int shop, int movie) {
        // isme bas rented wale funcn ka ulta kr do

        // pehle nikalo ye konsi wali movie hai kitne price ki

        // iss movie ko rakhne wale sab bando ko nikalo
        // auto it = movitoshop[movie];

        // iss set me lower bound laga dena, to get cheapest banda with same
        // shop and same movie
        // auto it2 = it.lower_bound({shop, INT_MIN});
        // new way to use lower bound, gives smallest banda with value>=shop

        // dono kaam ek sath kardo
        auto it2 = movitoshop[movie].lower_bound({shop, INT_MIN});
        // O(logn) for check

        // price nikal lo isse ab
        int price = it2->second;

        // ab is movie ko rented wale se alag kardo, since ab isko vapas bhejre
        // hai
        rented.erase({price, shop, movie});
        // O(logn) for erase

        // and then insert it into the available wala map, since this movie
        // available for purchase
        available[movie].insert({price, shop});
        // O(logn) for insert
    }

    // again overall const time O(const)
    vector<vector<int>> report() {
        vector<vector<int>> ans;

        int cnt = 0;

        // rented wale bando me iterate karo
        for (auto& [price, shop, movie] : rented) {
            // rented set hai,toh vo apne aap first price ke hisab se rakhega,
            // then shop ke hisab se, then movie ke hisab se

            // toh top ke 5 bande already cheapest honge, since ascending order
            // hota

            // toh bas 5 bande utha lo and kaam khatam

            // current banda daal do
            ans.push_back({shop, movie});
            // increment count
            cnt++;
            // ab agar cnt>=5 hua toh break kardo since 5 bande chahiye the bas
            if (cnt >= 5)
                break;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */