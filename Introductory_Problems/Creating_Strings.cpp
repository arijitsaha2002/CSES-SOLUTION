#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

string next_string(string s) {
    int right_index = s.size() - 1;
    while(right_index > 0 and s[right_index] <= s[right_index - 1]) right_index --;
    if(right_index == 0) return "";
    right_index --;
    int swap_index = s.size() - 1;
    while(s[swap_index] <= s[right_index]) swap_index --;
    swap(s[swap_index], s[right_index]);
    reverse(s.begin() + right_index + 1, s.end());
    return s;
}    

int main () {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> answers;
    while(s.size()) {
        answers.push_back(s);
        s = next_string(s);
    }
    cout << answers.size() << endl;
    for(auto v: answers) cout << v << "\n";
    return 0;
}    
