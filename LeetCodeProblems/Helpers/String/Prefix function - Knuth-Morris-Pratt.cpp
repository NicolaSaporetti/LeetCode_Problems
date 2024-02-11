//Prefix lengh that is also a suffix
//"abcabcd" is  [0, 0, 0, 1, 2, 3, 0] 
//"aabaaab" is  [0, 1, 0, 1, 2, 2, 3]

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}