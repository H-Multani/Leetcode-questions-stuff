class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // string me daal do
        string start = "";
        for (auto it : board) {
            for (auto it2 : it) {
                start += to_string(it2);
            }
        }

        string target = "123450";

        // bfs ke liye queue banao
        queue<string> q;
        // q me push kardo starting
        q.push(start);

        // kis idx par khade hoke kis idx tak jaa sakte hai, map banao uska
        unordered_map<int, vector<int>> mpp;
        mpp[0] = {1, 3};
        mpp[1] = {0, 2, 4};
        mpp[2] = {1, 5};
        mpp[3] = {0, 4};
        mpp[4] = {1, 3, 5};
        mpp[5] = {2, 4};

        // since swap karne ke baad vapas thodi aana hai apan ko purani posn par
        unordered_set<string> visited;
        // starting wala already visited hai, usko visited me push kardo
        visited.insert(start);

        // BFS chala do
        int lvlcnt = 0;
        while (!q.empty()) {
            // current lvl me kitne elements hai
            int n = q.size();

            // iss level ke har element par jaa kar processing karo
            while (n--) {
                // current string is
                string curr = q.front();
                q.pop();

                // agar yehi current wala string target pahuch gaya hai toh yehi
                // se ans return kardo
                if (curr == target)
                    return lvlcnt;

                // current string me 0 ka index is
                int zeroidx = curr.find('0');

                // ab iss index ka swap apan konse konse indexes ke element se
                // kar sakte hai map se nikal lo, ye next level ke liye elements
                // rahenge
                // har neighbour par jao pehle toh
                for (auto neighbor : mpp[zeroidx]) {
                    // agar current 0 idx wale element ko current neighbor se
                    // swap maroge toh kya string banegi nikalo
                    string newstate = curr;
                    swap(newstate[zeroidx], newstate[neighbor]);
                    // yehi newstate string banegi

                    // agar already visited state hai toh koi need nai h visit
                    // karne ki isko phir se, since it'll be like going frm 1 to
                    // 2 then 2 me explore karte time going back to 1, we dont
                    // want that
                    // jaha ek baar explore kar liye hai waha phir se explore
                    // karne ka need nai hai
                    if (visited.find(newstate) == visited.end()) {
                        // means iss state ko apan ne pehle kabhi nai dekha hai
                        // and first time aaye hai iss state par, hence visited
                        // me daal do and q me push kardo further levels me
                        // explore karne ke liye
                        visited.insert(newstate);
                        q.push(newstate);
                    }
                }
            }

            // ab we are here means purana level explore kar chuke hai and ans
            // nai mila hai, means possible hai ans next level me ho, toh
            lvlcnt++;
            // indicates that we have moved 1 level deeper

            // now we move onto the next level
        }

        // if we are here means pura BFS chalane ke baad bhi answer possible nai
        // mila, ie kitne bhi swapping macha do target tak nai pahuch payenge,
        // in such case return -1
        return -1;
    }
};