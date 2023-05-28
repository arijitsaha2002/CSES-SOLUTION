#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

#define ll long long
#define Point pair<int, int>

Point A, B;
int n, m;

bool notVisited[1000][1000];

class Node {
public:
    int x, y;
    int px, py;
    Node(int a, int b, int c = -1, int d = -1) {
        x = a;
        y = b;
        px = c;
        py = d;
    }
    Node() {}
};



char Diff(Point &a, Point &b) {
    int dy = a.first - b.first;
    int dx = a.second - b.second;
    if (dx == 0 and dy < 0) return 'D';
    if (dx == 0 and dy > 0) return 'U';
    if (dx > 0) return 'L';
    return 'R';
}

bool bfs(int x, int y, vector<vector<Point>> &D) {

    queue<Point> pending;
    pending.push(A);



    while (not pending.empty()) {
        Point f = pending.front();

        if (f.first == B.first and f.second == B.second) {

            Point parent;
            string s = "";
            do {
                parent = D[f.first][f.second];
                s += Diff(parent, f);
                f = parent;
            } while (f != A);
            reverse(s.begin(), s.end());
            cout << "YES\n" << s.size() << "\n" << s << endl;
            return true;
        }



        if (f.first > 0 and notVisited[f.first - 1][f.second]) {
            notVisited[f.first - 1][f.second] = false;
            Point Temp(f.first - 1, f.second);
            D[Temp.first][Temp.second].first = f.first;
            D[Temp.first][Temp.second].second = f.second;
            pending.push(Temp);
        }
        if (f.second > 0 and notVisited[f.first][f.second - 1]) {
            notVisited[f.first][f.second - 1] = false;
            Point Temp(f.first, f.second - 1);
            D[Temp.first][Temp.second].first = f.first;
            D[Temp.first][Temp.second].second = f.second;
            pending.push(Temp);
        }

        if (f.first < n-1 and notVisited[f.first + 1][f.second]) {
            notVisited[f.first + 1][f.second] = false;
            Point Temp(f.first + 1, f.second);
            D[Temp.first][Temp.second].first = f.first;
            D[Temp.first][Temp.second].second = f.second;
            pending.push(Temp);
        }
        if (f.second < m-1 and notVisited[f.first][f.second + 1]) {
            notVisited[f.first][f.second + 1] = false;
            Point Temp(f.first, f.second + 1);
            D[Temp.first][Temp.second].first = f.first;
            D[Temp.first][Temp.second].second = f.second;
            pending.push(Temp);
        }
        pending.pop();
    }

    return false;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector<vector<Point>> D(n, vector<Point>(m));

    char c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            notVisited[i][j] = (c != '#');
            if (c == 'A') {
                A.first = i;
                A.second = j;
            }
            else if (c == 'B') {
                B.first = i;
                B.second = j;
            }
        }
    }

    if (not bfs(A.first, A.second, D)) {
        cout << "NO\n";
    }

    return 0;
}