class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // ez sort karke lagate jao, agar kahi bhi asteroid nai toot raha toh
        // wahi break return false

        // sort isliye since smaller asteroid jaldi tootenge and bigger tak
        // pahuchte pahuchte mass bada bn jayega

        long long ans=mass;

        sort(asteroids.begin(), asteroids.end());

        for (auto it : asteroids) {
            if (ans < it) {
                // means this asteroid cannot be broken in such case return
                // false, since mass weak hai aven after eating all the smaller
                // asteroids, and since current nai toot raha toh aage wale bhi
                // nai tootenge since aage wale aur heavy
                

                // in such case return false
                return false;
            }

            // we here means asteroid broken, add kardo mass me
            ans+=it;
        }

        // we here means all broken
        return true;
    }
};