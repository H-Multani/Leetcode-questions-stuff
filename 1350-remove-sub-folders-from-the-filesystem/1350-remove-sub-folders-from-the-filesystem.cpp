class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // store all possible options for folders in set, so that jaldi mil
        // paaye if a string is a folder or not
        unordered_set<string> st(folder.begin(), folder.end());

        vector<string> ans;

        for (auto it : folder) {
            // current folder is 'it'

            bool issubfolder = false;
            // to chk if current banda is a sub folder, since agar sub folder
            // hai means remove karna hai

            // current folder ka copy rakh lo, since original ko toh apan ne ab
            // bhej diya loop me
            string original = it;

            // jab tak current folder empty nai ho jata
            while (it != "") {
                // last ke 2 characters(works only when we have stuff like /a/b
                // etc, not when we have /abc/erv etc) trim karke, remaining
                // substring nikalo,

                // last ke 2 since we need posn of last '/' basically
                // iske aage wala saara substring ignore maar do,
                // bacha kucha substring nikalo
                size_t idx = it.find_last_of('/');
                // gives us index of last occurence of '/' character
                // size_t, since ye funcn jo data type return krta hai vo size_t
                // hota h aisa samajh lo

                // current substring will be
                it = it.substr(0, idx);

                // this substring can be a folder,
                // if ye substring set me present hai, means ye substring folder
                // hai, and that means original jo string thi, vo ek subfolder
                // thi bas, toh matlab original banda ek subfolder hai, and its
                // not a folder, toh boolean value ko true set kar do
                if (st.find(it) != st.end()) {
                    issubfolder = true;
                    break;
                }
            }

            // if current(original) banda WASNT a sub folder, then add that to result
            // since sub folders ko remove karna tha apan ko
            if (!issubfolder) {
                ans.push_back(original);
            }
        }

        return ans;
    }
};