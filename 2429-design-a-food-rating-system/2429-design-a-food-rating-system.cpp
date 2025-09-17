class FoodRatings {
public:
    // aise likha jata hai custom comparator for set
    struct comp {
        bool operator()(const pair<string, int>& p1,
                        const pair<string, int>& p2) const {
            if (p1.second > p2.second)
                return true;
            if (p1.second == p2.second) {
                // send the one with smaller string
                if (p1.first < p2.first)
                    return true;
                else
                    return false;
            }

            return false;
        }
    };
    // food to rating
    unordered_map<string, int> mp1;
    // food to cuisine
    unordered_map<string, string> mp2;
    // now cuisine to set<food,rating> wala, set me custom comparator laga
    // denge
    unordered_map<string, set<pair<string, int>, comp>> mp3;

    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        // firstly map food to rating and food to cuisine
        int n = f.size();

        for (int i = 0; i < n; i++) {
            // food to rating
            mp1[f[i]] = r[i];
            // food to cuisine
            mp2[f[i]] = c[i];
        }

        // ab set banega with custom comparator

        // ab bhar do set wale map ko
        for (int i = 0; i < n; i++) {
            mp3[c[i]].insert({f[i], r[i]});
        }
    }

    void changeRating(string food, int nr) {
        // sabse pehle iss food ka cuisine nikalo
        string c = mp2[food];

        // ab iss cuisine me jaa kar new value update kardo set me

        // lekin agar old value is bigger, toh new insert karne se kuch nai
        // hoga, since older will be at top

        // to counter that firstly, purana wala food and rating nikalo
        int oldrating = mp1[food];

        // ab ye {food,oldrating} wala pair cuisine ke set se alag kardo,
        // (ye set ke front par hoga agar maxm hoga toh), alag kar denge toh
        // instance hi udd jayega iss food ka , toh apne aap second best ans aa
        // jaega upar
        mp3[c].erase({food, oldrating});

        // new rating update kardo map me
        mp1[food] = nr;

        // new wala {food,newrating} pair daal do mp3 wale map me cuisine ke
        // against

        // map me daal do, since custom comparator hai, hence apne aap sahi posn
        // aa jayegi
        mp3[c].insert({food, nr});
    }

    string highestRated(string cuisine) {
        // apan ne cuisine ke set wala map aisa banaya hai ki largest rating
        // wala cuisine starting me rahega, and agar same rating hai toh smaller
        // string wala aage rahega

        // cuisine ke set ka first banda ka string bhej do vahi ans hai
        // basically cuisine->{food,rating} , iska food wala part bhej do, first
        // element ka
        return mp3[cuisine].begin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */