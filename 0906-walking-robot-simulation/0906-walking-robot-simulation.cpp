class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> st;
        for (auto it : obstacles) {
            pair<int, int> temp;
            temp.first = it[0];
            temp.second = it[1];
            st.insert(temp);
        }
        pair<int, int> finalcood;
        finalcood.first = 0;
        finalcood.second = 0;
        int currfacing = 0; // 0 for north,1 for east,2 for south,3 for west
        int ans = (finalcood.first) * (finalcood.first);
        ans += (finalcood.second) * (finalcood.second);
        for (auto it : commands) {
            if (it == -1 || it == -2) {
                if (it == -1) {
                    currfacing = (currfacing + 1) % 4;
                } else {
                    currfacing = (currfacing + 3) % 4;
                }
            } else {
                if (currfacing == 0) {
                    // go north, increase finalcood.second only
                    pair<int, int> curr = finalcood;
                    int dist=it;
                    while (it--) {
                        // current cood is curr
                        curr.second += 1;
                        if (st.find(curr) != st.end()){
                            // obstacle found, move to prev step
                            curr.second--;
                            break;
                        }
                    }
                    finalcood = curr;
                } else if (currfacing == 1) {
                    // go east, increase finalcood.first only
                    cout << "this part ran " << 1 << endl;
                    pair<int, int> curr = finalcood;
                    cout<<it<<" blrh"<<endl;
                    while (it--) {
                        // current cood is curr
                        curr.first++;
                        if (st.find(curr) != st.end()){
                            // means obstacle found, move back to previous step
                            curr.first--;
                            break;
                        }
                    }
                    finalcood = curr;
                } else if (currfacing == 2) {
                    // go south, decrease finalcood.second only
                    pair<int, int> curr = finalcood;
                    while (it--) {
                        // current cood is curr
                        curr.second--;
                        if (st.find(curr) != st.end()){
                            // obstacle found, move to prev step
                            curr.second++;
                            break;
                        }
                    }
                    finalcood = curr;
                } else {
                    // go west, decrease finalcood.first only
                    pair<int, int> curr = finalcood;
                    while (it--) {
                        // current cood is curr
                        curr.first--;
                        if (st.find(curr) != st.end()){
                            // obstacle found, move to prev step
                            curr.first++;
                            break;
                        }
                    }
                    finalcood = curr;
                }
            }
            cout << finalcood.first << " " << finalcood.second<<" "<<currfacing << endl;
            int currans=((finalcood.second) * (finalcood.second))+((finalcood.first) * (finalcood.first));
            // update ans, incase this is the furthest coordinate we went to from origin
            ans= max(ans,currans);
        }
        
        return ans;
    }
};