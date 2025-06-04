using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;

class DSU {
    int components;

public:
    vi parent;
    vi sizee;
    DSU(int nodes) {
        // jitne nodes hai utne parent ke locations banao
        parent.resize(nodes);
        sizee.resize(nodes, 1);
        iota(parent.begin(), parent.end(), 0);

        components = nodes;
    }

    // finds super parent of current node u
    int parentt(int u) {

        if (parent[u] == u)
            return u;

        return parent[u] = parentt(parent[u]);
    }

    // joins node u and v
    void unionSets(int u, int v) {
        // nodes u and v diye hai, dono ke super parents nikalo

        int super_parent_of_u = parentt(u), super_parent_of_v = parentt(v);

        if (super_parent_of_u == super_parent_of_v)
            return;

        // we do this so that u wala node is always the one with bigger parent

        // if (sizee[super_parent_of_u] < sizee[super_parent_of_v])
        //     swap(super_parent_of_u, super_parent_of_v);

        // here we do one additional thing, we need ki smaller value wala banda
        // parent bane, like bw u and v, if we have u<v we need ki u becomes
        // overall parent in all cases

        // imagine v=3 uska super parent=3, u=6 uska super parent=5
        // we need ki overall join ke baad super parent is 3

        // before super_parent_of_u=5,super_parent_of_v=3
        if (super_parent_of_u > super_parent_of_v)
            swap(super_parent_of_u, super_parent_of_v);
        // after super_parent_of_u=3,super_parent_of_v=5

        // yaha apan overall super parent u ko bana rahe hai, toh needed ki iss
        // step se pehle u has the smallest super parent
        parent[super_parent_of_v] = super_parent_of_u;
        sizee[super_parent_of_u] += sizee[super_parent_of_v];
        components--;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // DSU me apan ne changes kar diye hai

        // ab size 26 ka DSU lo, since 26 chars hai bas
        DSU dsu(26);

        // ab dono s1 and s2 me iterate karo
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            // dono char ko dsu se join kardo
            // cout << s1[i] << "   " << s2[i] << endl;
            // cout << dsu.parent[s1[i] - 'a'] << "   " << dsu.parent[s2[i] - 'a']
            //      << endl;
            dsu.unionSets(s1[i] - 'a', s2[i] - 'a');

            // cout << "done " << endl;

            // cout << s1[i] << "   " << s2[i] << endl;
            // cout << dsu.parent[s1[i] - 'a'] << "   " << dsu.parent[s2[i] - 'a']
            //      << endl;
        }

        // done, ab bas basestr se string banao

        string ans = "";

        // for (auto i = 0; i < 26; i++) {
        //     cout << (char)('a' + i) << " ";
        //     if (i > 9)
        //         cout << " ";
        // }
        // cout << endl;

        // for (auto it : dsu.parent) {
        //     cout << it << " ";
        // }

        // cout << endl;

        for (auto ch : baseStr) {
            // curr char is ch

            // iss char ka super parent kon hai nikalo

            // toh thing is DSU me updated hai lekin parent updated nai hai
            // finally wala, like in eg2 initial wala 'o' ka parent 14 se 4 kar
            // diya, lekin baad me same 'o' ka parent 3 assign kar diya tha(jo
            // ki karna hi tha, lekin assign kara tha bas, parent array me
            // update nai kiya tha), we needed to call the parentt(v) funcn one
            // time to update final things in the parent array

            // and parentt(v) funcn return bhi kar dega toh seedha funcn call ka
            // ans hi dedo, this funcn call will not take alot of time btw,
            // since we just need to update parent vector one last time for each
            // char, toh sabka karne se accha h ki reqd wale ka karo bss

            // otherwise,overall this parentt funcn will be O(1) in terms of
            // T.C.

            // toh parentt funcn call kardo ek baari
            int spparent = dsu.parentt(ch - 'a');

            // iss parent ka corr char nikalo
            ans += (char)('a' + spparent);
        }

        return ans;
    }
};