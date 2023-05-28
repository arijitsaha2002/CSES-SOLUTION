#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long


int getParent(int *C, int n) {
    while (C[n] != -1) n = C[n];
    return n;
}

bool isVisited[100001];
int C[100001];
bool S[100001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, i, j, t;
    cin >> n >> m;

    // unordered_set<int> S;

    while (m--) {
        cin >> i >> j;
        if (isVisited[i]) {

            // int pi = getParent(C, i), pj;

            if (isVisited[j]) {
                // pj = getParent(C, j);
                // if (pi != pj) {
                //     C[pi] = pj;
                //     S[pi] = false;
                // }
            }
            else {
                // C[j] = pi;
                isVisited[j] = true;
            }
        }
        else if (isVisited[j]) {

            // int pj = getParent(C, j), pi;
            // // C[j] = pj;

            if (isVisited[i]) {
                // pi = getParent(C, i);

                // if (pi != pj) {
                //     C[pi] = pj;
                //     S[pi] = false;

                // }
            }
            else {
                // C[i] = pj;
                // isVisited[i] = true;
            }


        }
        else {
            isVisited[i] = true;
            isVisited[j] = true;
            C[i] = -1;
            C[j] = i;
            S[i];
        }
    }

    // for (int i = 1; i <= n; i ++) {
    //     if (not isVisited[i]) S[i];
    // }

    // cout << S.size() - 1 << endl;

    // for (; it != S.end() ; it++) {
    //     cout << *prev << " " << *it << endl;
    //     prev ++;
    // }


    return 0;
}