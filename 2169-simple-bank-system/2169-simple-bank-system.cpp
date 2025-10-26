class Bank {
    // simulate hi kardo aur kya itne n size ka array easily ban jana chahiye
    vector<long long> bank;
    long long n;

public:
    Bank(vector<long long>& balance) {
        n = balance.size();

        bank.assign(n, 0);

        for (auto i = 0; i < n; i++) {
            bank[i] = balance[i];
        }
    }

    bool transfer(int acc1, int acc2, long long money) {
        // edge case agar acct no valid nai hai toh return false
        if (acc1 > n || acc2 > n)
            return false;

        // acc1 me money hai??
        if (bank[acc1 - 1] < money) {
            // money nai hai return false
            return false;
        }

        // acc1 se money nikalo acc2 me daalo
        bank[acc1 - 1] -= money;
        bank[acc2 - 1] += money;

        return true;
    }

    bool deposit(int account, long long money) {
        // edge case agar acct no valid nai hai toh return false
        if (account > n)
            return false;
        // iss wale acct me jaa kar deposit kardo money ko
        bank[account - 1] += money;

        // deposit toh hamesha kar payenge na add kardo
        return true;
    }

    bool withdraw(int acc, long long money) {
        // edge case agar acct no valid nai hai toh return false
        if (acc > n)
            return false;
        // agar iss acct me money nai hai toh return false else return true
        if (bank[acc - 1] < money)
            return false;

        bank[acc - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */