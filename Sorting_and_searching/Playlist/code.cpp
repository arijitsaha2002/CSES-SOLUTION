#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> counter;

    int n; cin >> n;

    int songs[n];
    for_each(songs, songs + n, [](int &song) { cin >> song; });

    int i = 0, j = 1, max_length = 1;
    counter[songs[i]]++;

    while (j < n) {
        if (counter.find(songs[j]) != counter.end()) {
            while (i <= counter[songs[j]]) {
                counter.erase(songs[i]);
                i ++;
            }
        }

        counter[songs[j]] = j;
        j ++;
        max_length = max(max_length, j - i);
    }

    cout << max_length << newline;
    return 0;
}