class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        // jitne right jaa rhe h sab push karo(health) stack me, along with the
        // index agar left mila toh pop karna h, like top se compare karna hai,
        // agar collosion hua(hoga hi bcoz right ke liye jab left milega tab hi
        // compare karenge otherwise no, since all in same direction are going
        // the same speed, so right jaane waale sab me koi collision nahi hoga
        // ever)

        // agar collision hua toh accordingly uski health changes karne hai accd
        // to question, and if a robot removed, use health ke value -1 kar denge

        // stack<pair<long long, long long>> st;

        // first create a data str,that stores all the values, and sort accd to
        // positions, bcoz by default the posn are unsorted

        vector<vector<int>> overall;
        int len = healths.size();

        for (int i = 0; i < len; i++) {
            vector<int> temp;
            temp.push_back(positions[i]);
            temp.push_back(healths[i]);
            // if right, store 1, else store 0(for left)
            if (directions[i] == 'R')
                temp.push_back(1);
            else
                temp.push_back(0);

            overall.push_back(temp);
        }

        // now this overall vector stores vectors, in each vector theres 3
        // values, first is position, 2nd is health, 3rd is posn

        sort(overall.begin(), overall.end());

        // for (auto it : overall) {
        //     cout << "values are " << it[0] << " " << it[1] << " " << it[2]
        //          << endl;
        // }

        stack<pair<int, int>> st;
        // stack stores <health, index>
        // iterate thru the array overall and simulate the collisions

        for (int i = 0; i < len; i++) {
            if (overall[i][2] == 1) {
                // right jaa rha h, store in stack
                pair<int, int> temp;
                temp.first = overall[i][1];
                temp.second = i;
                st.push(temp);
            } else {
                // left jaa rha hai
                // if stack is empty this will continue to go left without
                // interruptions so leave it alone(no changes), since apan left
                // se iterate krke dekh rhe h, and agar pehle koi right me jane
                // wala nai mila hai(ie stack is empty) toh ye seedhe seedhe
                // left chala jaega no changes, no collisions anything, since
                // right se koi aa nai rha hai, toh collisions kaise hi hoga

                // cout<<"here "<<st.empty()<<endl;
                if (!st.empty()) {
                    // operations only when stack is not empty

                    // left jane wala mila h, and right se aane wale stack me h,
                    // collision hoga with stack top

                    // left jane wale ka health is more than right jane wala
                    // loop on the stack coz there could be ki left wala sabko
                    // hara de

                    // checked stack empty first bcoz otherwise iteration me
                    // agar stack empty hua toh reference error de dega bcoz its
                    // trying to seach fot the stack top when stack empty, thats
                    // why ye pehle chk krna padta h ki stack empty h ki nai
                    // (first submission ka runtime error iss first stack empty
                    // check se hi fix hua)
                    while (!st.empty() && overall[i][1] >= st.top().first) {
                        if (overall[i][1] == st.top().first) {
                            // cout << "same values " << overall[i][1] << " "
                            //  << st.top().first << endl;
                            // dono ka same health, both are out
                            // dono ka health set to -1

                            // left jane wale ka health to -1
                            overall[i][1] = -1;

                            // right jane wale ka health -1
                            overall[st.top().second][1] = -1;
                            // pop from stack
                            st.pop();

                            // ab toh i th wali ka value -1 kar diya hai, no
                            // need to check with anything further, so get out
                            // of the loop
                            break;
                        } else {
                            // top wale ka health -1 karo,
                            overall[st.top().second][1] = -1;
                            // current wale ka health decrease by 1
                            overall[i][1]--;
                            // top wale ko pop kar do
                            st.pop();
                        }
                    }

                    // after the loop, 2 cases, 1st is current wala ka value -1
                    // ho chuka hai(== wala case inside the while loop)(ie it
                    // cant be used anymore), in which case do nothing goto next
                    // i

                    // case 2 is when current wale ka health < stack top ka
                    // health, in this case, top wale ka health decrease by 1
                    // and current wale ka health set to -1, the if case is for
                    // that only
                    if (!st.empty() && overall[i][1] < st.top().first &&
                        overall[i][1] != -1) {
                        // so chk if stack is empty first, bcoz agar empty hai,
                        // toh current wale ko stop krne ke liye koi nai h, so
                        // nothing to be done

                        // then check if current wale ka health<stack top wale
                        // ka health

                        // then check ki kahi current ka value -1 toh nai, bcoz
                        // agar hoga toh upar wala paas karega bcoz all
                        // values>-1, that we dont want, bcoz health -1 hone ke
                        // baad bo element gayan ho chuka h and its no longer of
                        // any use

                        // cout << "works " << endl;

                        // decrease value of health by 1 both in the overall
                        // array as well as in the stack overall me toh pata h
                        // changes confirm krne ke liye kam krna h, but we
                        // change in the stack bcoz when we compare we take the
                        // value from the stack top and not the overall
                        // array,hence we have to make the changes to the stack
                        // health value as well(see the wa submission tesecase,
                        // dry run the testacase normally and then by the corr
                        // code, we see that stack me changes nai aa rha hai, so
                        // instead of comparing with 47 we compare with 48 which
                        // is wrong )
                        // decrease in the overall array->
                        overall[st.top().second][1]--;
                        // decrease in the stack->
                        st.top().first--;

                        overall[i][1] = -1;
                    }
                }
            }
        }

        // for (auto it : overall) {
        //     if (it[1] != -1) {
        //         cout << it[1] << " ";
        //     }
        // }

        // key value pairs banao overall arrya ka
        // key is position, and value is health

        unordered_map<int, int> mpp;

        for (auto it : overall) {
            if (it[1] != -1) {
                // push to map
                mpp[it[0]] = it[1];
            }
        }
        // push the values in the order of position array to a final ans vector
        // to be returned
        vector<int> ans;
        for (auto it : positions) {
            if (mpp.find(it) != mpp.end()) {
                // cout << mpp[it] << " ";
                ans.push_back(mpp[it]);
            }
        }

        // cout << endl;

        return ans;
    }
};