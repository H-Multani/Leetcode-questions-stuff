class Spreadsheet {
public:
    // ek map bana lo which will store the <char,index> and its value
    map<pair<char, int>, int> mp1;
    Spreadsheet(int rows) {
        // yaha kuch karne ke need nai hai

        // mp1 ko initialize kardo
    }

    pair<char, int> getcood(string s) {
        // cout << s << endl;
        // first character is the column
        char col = s[0];

        // bacha kucha is the row number, nikal lo
        string row = "";
        for (int i = 1; i < s.size(); i++) {
            row += s[i];
        }

        // ab iss row ko integer me convert karke bhej do
        int r = stoi(row);

        return {col, r};
    }

    void setCell(string cell, int value) {
        // set me iss cell wala value update kardo

        // pehle toh nikalo konsa cell hai
        pair<char, int> c = getcood(cell);

        // cell mil gaya, ab iss cell ki value update kardo
        mp1[c] = value;

        // print karlo ek baari
        // for(auto it:mp1){
        //     cout<<"<"<<it.first.first<<","<<it.first.second<<">="<<it.second<<endl;
        // }
        // cout<<endl;
        return;
    }

    void resetCell(string cell) {

        // iska bas cell nikal kar dekh lo, agar map me hai toh remove kardo map
        // se, save some space, since iss cell ka value 0 karna hai, and non
        // mentioned cells already are at value 0,
        pair<char, int> c = getcood(cell);

        if (mp1.find(c) != mp1.end()) {
            // remove frm map
            mp1.erase(c);
        }
        return;
    }

    int getValue(string f) {

        // 2 cells hai nikal lo
        pair<char, int> c1;
        pair<char, int> c2;

        int val1, val2;
        string temp = "";

        for (int i = 1; i < f.size(); i++) {
            // cout<<""<<temp<<endl;
            if (f[i] == '+') {
                // its possible ki temp is not a coordinate but a value
                if (temp[0] >= 'A' && temp[0] <= 'Z') {
                    // means coordinate hai, nikal lo
                    c1 = getcood(temp);
                    // value nikal lo yehi se
                    if (mp1.find(c1) == mp1.end())
                        val1 = 0;
                    else
                        val1 = mp1[c1];
                } else {
                    // value hai
                    val1 = stoi(temp);
                }

                temp = "";
                continue;
            }

            temp += f[i];
        }
        // cout<<temp<<endl;
        // its possible ki temp is not a coordinate but a value
        if (temp[0] >= 'A' && temp[0] <= 'Z') {
            // means coordinate hai
            c2 = getcood(temp);
            if (mp1.find(c2) == mp1.end())
                val2 = 0;
            else
                val2 = mp1[c2];
        } else {
            // value hai
            val2 = stoi(temp);
        }

        // cout<<val1<<" "<<val2<<endl;

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */