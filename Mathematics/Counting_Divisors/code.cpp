#include <iostream>
#include <unordered_map>
using namespace std;

const int MN = 1e6 + 1;

bool is_not_prime[MN];
int highest_div[MN];

void fill_prime() {
    is_not_prime[0] = is_not_prime[1] = 1;

    for (int i = 2; i < MN; i++) {
        if (!is_not_prime[i]) {
            highest_div[i] = i;
            for (int j = i << 1; j < MN; j += i) {
                is_not_prime[j] = true;
                highest_div[j] = i;
            }
        }
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    fill_prime();

    int q, x;
    cin >> q;

    while (q--) {
        cin >> x;

        unordered_map<int, int> M;

        while (x > 1) {
            M[highest_div[x]] ++;
            x /= highest_div[x];
        }

        int r = 1;
        for (auto m : M) {
            r *= (m.second + 1);
        }

        cout << r << "\n";

    }


    return 0;
}