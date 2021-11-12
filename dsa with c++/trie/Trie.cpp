#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int ALPH = 26;

int Trie[MAXN][ALPH], nc;
int endNodes[MAXN];

void insert(string s) {
    int len = s.length();
    int currNode = 0;  // start with root always

    for (int i = 0; i < len; i++) {
        if (Trie[currNode][s[i] - 'a'] == -1) {
            // there is no edge with label s[i]
            Trie[currNode][s[i] - 'a'] = ++nc;
        }

        currNode = Trie[currNode][s[i] - 'a'];
    }

    endNodes[currNode] = 1;  // this is last nodes for string s;
}

bool search(string s) {
    int len = s.length();
    int currNode = 0;  // start with root always

    for (int i = 0; i < len; i++) {
        if (Trie[currNode][s[i] - 'a'] == -1) {
            return false;
        }

        currNode = Trie[currNode][s[i] - 'a'];
    }

    if (endNodes[currNode] == 1) {
        return true;
    }

    return false;
}

int main(void) {
    nc = 0;

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < ALPH; j++) {
            Trie[i][j] = -1;
        }

        endNodes[i] = 0;
    }

    return 0;
}