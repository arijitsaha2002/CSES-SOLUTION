#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int height, width;
    cin >> height >> width;

    char c;
    vector<vector<bool>> Graph(height + 1, vector<bool>(width + 1, 0));
    vector<vector<bool>> is_visited(height + 1, vector<bool>(width + 1, false));
    vector<vector<Point>> parent(height + 1, vector<Point>(width + 1));

    set<Point> Monsters, Me;

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {

            cin >> c;

            Graph[i][j] = (c != '#');

            if (c == 'A') {
                Me.insert({i, j});
                is_visited[i][j] = true;
            }
            else if (c == 'M') {
                Monsters.insert({i, j});
            }
        }
    }




    while (true) {

    //     set<Point> temp;

    //     for (auto it = Monsters.begin(); it != Monsters.end(); it ++) {

    //         int x = it->first, y = it->second;

    //         if (x - 1 > 0) {
    //             if (y - 1 > 0) {
    //                 temp.insert(x - 1, y - 1);
    //             }
    //             if (y + 1 <= width) {
    //                 temp.insert(x - 1, y + 1);
    //             }
    //         }

    //         if (x + 1 <= height) {
    //             if (y - 1 > 0) {
    //                 temp.insert(x + 1, y - 1);
    //             }
    //             if (y + 1 <= width) {
    //                 temp.insert(x + 1, y + 1);
    //             }

    //         }

    //     }

    //     Monsters = temp;

    //     set<Point> temp2;
    //     int final_x, final_y;

    //     for (auto it = Me.begin(); it != Me.begin(); it ++) {
    //         int x = it->first, y = it->second;

    //         bool is_way = false;

    //         if (x - 1 > 0) {
    //             if (y - 1 > 0) {
    //                 if (Graph[x - 1][y - 1] and Monsters.find({x - 1, y - 1}) != Monsters.end() and not is_visited[x - 1][y - 1]) {
    //                     temp2.insert(x - 1, y - 1);
    //                     is_visited[x - 1][y - 1];
    //                     is_way = true;
    //                     parent[x - 1][y - 1] = {x, y};
    //                 }

    //             }
    //             else {
    //                 final_x = x;
    //                 final_y = y;
    //                 break;
    //             }
    //             if (y + 1 <= width) {
    //                 if (Graph[x - 1][y + 1] and Monsters.find({x - 1, y + 1}) != Monsters.end() and not is_visited[x - 1][y + 1]) {
    //                     temp2.insert(x - 1, y + 1);
    //                     is_visited[x - 1][y + 1];
    //                     is_way = true;
    //                     parent[x - 1][y + 1] = {x, y};
    //                 }

    //             }
    //             else {
    //                 final_x = x;
    //                 final_y = y;
    //                 break;
    //             }
    //         }

    //         if (x + 1 <= height) {

    //             if (y - 1 > 0 ) {
    //                 if (Graph[x + 1][y - 1] and Monsters.find({x + 1, y - 1}) != Monsters.end() and not is_visited[x + 1][y - 1]) {
    //                     temp2.insert(x + 1, y - 1);
    //                     is_visited[x + 1][y - 1];
    //                     is_way = true;
    //                     parent[x + 1][y - 1] = {x, y};
    //                 }

    //             }
    //             else {
    //                 final_x = x;
    //                 final_y = y;
    //                 break;
    //             }

    //             if (y + 1 <= width) {
    //                 if (Graph[x + 1][y + 1] and Monsters.find({x + 1, y + 1}) != Monsters.end() and not is_visited[x + 1][y + 1]) {
    //                     temp2.insert(x + 1, y + 1);
    //                     is_visited[x + 1][y + 1];
    //                     is_way = true;
    //                     parent[x + 1][y + 1] = {x, y};
    //                 }

    //             }
    //             else {
    //                 final_x = x;
    //                 final_y = y;
    //                 break;
    //             }

    //         }

    //         if (! is_way) {
    //             cout << "NO" << newline;
    //             return 0;
    //         }

    //     }

    //     Me = temp2;
    }


    return 0;
}
