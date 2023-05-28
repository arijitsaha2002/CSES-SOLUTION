#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    string A , B;
    cin >> A >> B;

    vector<uint32_t> T1(B.size() + 1);
    vector<uint32_t> T2(B.size() + 1);

    pair<vector<uint32_t>*, vector<uint32_t>*> Table;
    Table.first = &T1;
    Table.second = &T2;



    for (int i = 0; i < Table.second->size(); i++) {
        (*Table.second)[i] = i;
    }


    for (int i = 1; i <= A.size(); i++) {
        (*Table.first)[0] = i;
        for (int j = 1; j < Table.first->size(); j ++) {
            if (A[i - 1] == B[j - 1]) (*Table.first)[j] = (*Table.second)[j - 1];
            else (*Table.first)[j] = 1 + min((*Table.first)[j - 1], min((*Table.second)[j], (*Table.second)[j - 1]));
        }
        swap(Table.first, Table.second);
    }

    cout << (*Table.second)[B.size()] << endl;

    return 0;
}