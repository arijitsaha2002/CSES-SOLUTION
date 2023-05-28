#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long


class City {
public:
    int parent;
    bool isVisited;

    City() {
        isVisited = false;
    }
};

int getParent(City *C, int n) {
    while (C[n].parent != -1) n = C[n].parent;
    return n;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, i, j, t;
    cin >> n >> m;

    City C[n + 1];

    unordered_set<int> S;

    while (m--) {
        cin >> i >> j;
        if (C[i].isVisited) {

            int pi = getParent(C, i), pj;

            if (C[j].isVisited) {
                pj = getParent(C, j);
                if (pi != pj) {
                    C[pi].parent = pj;
                    S.erase(pi);
                }
            }
            else {
                C[j].parent = pi;
                C[j].isVisited = true;
            }
        }
        else if (C[j].isVisited) {

            int pj = getParent(C, j), pi;

            if (C[i].isVisited) {
                pi = getParent(C, i);

                if (pi != pj) {
                    C[pi].parent = pj;
                    S.erase(pi);

                }
            }
            else {
                C[i].parent = pj;
                C[i].isVisited = true;
            }


        }
        else {
            C[i].isVisited = true;
            C[j].isVisited = true;
            C[i].parent = -1;
            C[j].parent = i;
            S.insert(i);
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (not C[i].isVisited) S.insert(i);
    }

    cout << S.size() - 1 << endl;

    unordered_set<int>::iterator it = S.begin(), prev = it;
    it ++;

    for (; it != S.end() ; it++) {
        cout << *prev << " " << *it << endl;
        prev ++;
    }


    return 0;
}