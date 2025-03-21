class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        // pichle baar apan 1 baar iterate kar rhe tha bass, iss baar same cheez
        // ke liye N baar iterate karenge, since ho sakta h ki 4 th recipe
        // already ban jaaye, phir next iteration me  4 th ke use se 2 nd bane,
        // phir next iteration me 2 nd ke use se 5 th recipe bane and so onn

        // since n is also small toh ye brute foce chal jayega no worries

        int n = recipes.size();
        int cnt = n;

        // pehle saare supplies set me daal do, so that checkng easy ho jaaye
        unordered_set<string> st;
        for (auto it : supplies)
            st.insert(it);

        vector<string> ans;
        vector<bool> canbemade(n, false);
        while (cnt--) {
            // ab yaha iterate karo

            // iterate over all recipies and update which can be made
            for (int i = 0; i < n; i++) {
                // i th recipe par h abhi

                // agar i th recipe already made hai toh phir se chk krne ka
                // need nai h, continue to next recipe
                if (canbemade[i])
                    continue;

                // initially assume that recipe can be made
                bool curr = true;
                for (auto j : ingredients[i]) {
                    // agar current ingredient supply me nai h, toh ye recipe
                    // nai ban payegi
                    if (st.find(j) == st.end()) {
                        // means current ingredient is not in supply, ye recipe
                        // nai bana payenge
                        curr = false;
                        break;
                    }
                }

                // agar recipe can be made, toh uske against true mark kardo
                if (curr) {
                    // we here means ye recipe can be made, toh isko ab supplies
                    // me add kardo since it can be made, also so that now this
                    // new supply will be used to make other recipies(like eg2
                    // me bread becomes a supply)

                    // th ye recipe ko supply me add kardo
                    st.insert(recipes[i]);
                    canbemade[i] = true;

                    // we will only be here if koi phle nai banne wali recipe ab
                    // ban rahi hai, toh yehi se ans me add kardo
                    ans.push_back(recipes[i]);
                }
            }
        }

        // ab jitni recipies can be made unsab ko ans me daal do
        // for (auto i = 0; i < n; i++) {
        //     if (canbemade[i]) {
        //         ans.push_back(recipes[i]);
        //     }
        // }
        // iss loop ka kaam khatam kar diya

        return ans;
    }
};