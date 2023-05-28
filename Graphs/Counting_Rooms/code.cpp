#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define ll long long


class Point {
public:
    bool isTrue;
    int c;
    Point() {
        isTrue = false;
    }
};

int getBAP(Point *Arr, int value) {
    while (Arr[value].c != -1) {
        value = Arr[value].c;
    }
    return value;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, counter = 0;
    cin >> n >> m;
    char c;

    Point Arr[1024 * 1000];



    for (int i = 0; i < 1 ; i++) {
        cin >> c;
        if (c == '.') {
            Arr[(i << 10)].isTrue = true;
            Arr[(i << 10)].c = -1;
            counter ++;
        }

        for (int j = 1; j < m; j++) {
            cin >> c;
            if (c == '.') {
                if (not Arr[(i << 10) + j - 1].isTrue) {
                    counter ++;
                    Arr[(i << 10) + j].c = -1;
                }
                else {
                    Arr[(i << 10) + j].c = getBAP(Arr, (i << 10) + j - 1);
                }
                Arr[(i << 10) + j].isTrue = true;
            }
        }
    }


    for (int i = 1; i < n ; i++) {
        cin >> c;
        if (c == '.') {
            if (not Arr[((i - 1) << 10)].isTrue) {
                counter ++;
                Arr[(i << 10)].c = -1;
            }
            else {
                Arr[(i << 10)].c = getBAP(Arr, ((i - 1) << 10));
            }
            Arr[(i << 10)].isTrue = true;
        }


        for (int j = 1; j < m; j++) {
            cin >> c;
            if (c == '.') {
                if (Arr[(i << 10) + j - 1].isTrue and Arr[(((i - 1) << 10)) + j].isTrue) {
                    int b1 = getBAP(Arr,(i << 10) + j - 1);
                    int b2 = getBAP(Arr,((i - 1) << 10) + j);
                    if(b1 != b2){
                        Arr[b1].c = b2;
                        counter --;
                    }
                    Arr[(i << 10) + j].isTrue = true;
                    Arr[(i << 10) + j].c = b2;

                }
                else if (Arr[(i << 10) + j - 1].isTrue) {
                    Arr[(i << 10) + j].isTrue = true;
                    Arr[(i << 10) + j].c = getBAP(Arr,(i << 10) + j - 1);            
                }
                else if(Arr[((i - 1) << 10) + j].isTrue){
                    Arr[(i << 10) + j].isTrue = true;
                    Arr[(i << 10) + j].c = getBAP(Arr,((i - 1) << 10) + j);
                }
                else {
                    counter ++;
                    Arr[(i << 10) + j].isTrue = true;
                    Arr[(i << 10) + j].c = -1;
                }
            }
        }
    }

    cout << counter << endl;

    return 0;
}