#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define Point pair<int, int>
#define M 1000000007
#define newline '\n'
#define blankchar ' '
const int max_n = 1e6 +4;
int counter[max_n];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    Point songs[n];

    for (int index = 0; index < n; index ++) {
        cin >> songs[index].second;
        songs[index].first = index;
    }

    sort(songs, songs + n, [](Point & p1, Point & p2) { return p1.second < p2.second; });

    int hash_value = 0, prev = songs[0].second;
    songs[0].second = hash_value;

    for (int index = 1; index < n; index++) {
        if (songs[index].second == prev) {
            songs[index].second = hash_value;
        }
        else {
            hash_value ++;
            prev = songs[index].second;
            songs[index].second = hash_value;
        }
    }

    sort(songs, songs + n, [](Point & p1, Point & p2) { return p1.first < p2.first; });


    int i = 0, j = 1, max_length = 1;
    counter[songs[i].second] = 1;

    while (j < n) {

        if (counter[songs[j].second]) {
            while (i < counter[songs[j].second]) {
                counter[songs[i].second] = 0;
                i ++;
            }
        }


        counter[songs[j].second] = j + 1;
        j ++;
        max_length = max(max_length, j - i);

    }

    cout << max_length << newline;
    return 0;
}