#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define ff first
#define ss second
#pragma GCC optimize("O3","unroll-loops")
using namespace std;

/// I/O template starts ///
//#define windows_system
#define MAX_input_size 20000
#define MAX_output_size 50

#ifdef windows_system
/* For Windows */
inline int getchar_unlocked() { return getchar(); }
inline void putchar_unlocked(char _c) { putchar(_c); }
inline void fputs_unlocked(char* ans, FILE* strm) {fputs(ans, strm);}
inline void fread_unlocked(char* str, int bytes, int sz, FILE* strm) {fread(str, bytes, sz, strm);}
#endif

char output[MAX_output_size], input[MAX_input_size];
int input_ind = -1, output_ind = -1;

inline void GetInput() {
    fread_unlocked(input, 1, MAX_input_size, stdin);
}
inline char gc() {
    input_ind++;
    if (input_ind == MAX_input_size) {
        int tmp = fread_unlocked(input, 1, MAX_input_size, stdin);
        if (tmp < MAX_input_size) input[tmp] = '\0';
        input_ind = 0;
    }
    return input[input_ind];
}
inline void ReadPositiveInt(int *x) {
    static char c;
    while ((c = gc()) < '-') {
        if (c == '\0') return;
    }
    // no check for negative numbers
    *x = c - '0';
    while ((c = gc()) >= '0')
        * x = (*x << 3) + (*x << 1) + c - '0';
    return;
}
inline void PutInt(int x) {
    static short c[11];
    static int ind = 0;
    while (x != 0) {
        c[ind] = x % 10 + '0';
        ind++;
        x /= 10;
    }
    ind--;
    for (; ind >= 0; ind--) {
        output_ind++;
        output[output_ind] = c[ind];
    }
    return;
}
inline void PutChar(char c) {
    output_ind++;
    output[output_ind] = c;
    return;
}
inline void OutputFlush() {
    output[output_ind + 1] = '\0';
    fputs_unlocked(output, stdout);
    output_ind = -1;
    return;
}
/// I/O template ends ///

inline void radix_sort(pii* a, int n) {
    int cnt[32768] = {0};
    pii tmpa[n];
    loop(i, 0, n)
    cnt[a[i].ss & 32767]++;
    loop(i, 1, 32768)
    cnt[i] += cnt[i - 1];
    int temp;
    for (int i = n - 1; i >= 0; i--) {
        temp = (a[i].ss) & 32767;
        cnt[temp]--;
        tmpa[cnt[temp]] = a[i];
    }

    int cnt2[32768] = {0};
    loop(i, 0, n)
    cnt2[(tmpa[i].ss >> 15) & 32767]++;
    loop(i, 1, 32768)
    cnt2[i] += cnt2[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        temp = (tmpa[i].ss >> 15) & 32767;
        cnt2[temp]--;
        a[cnt2[temp]] = tmpa[i];
    }
    return;
}

int main() {
    GetInput();
    int n;
    ReadPositiveInt(&n);
    pii a[n + 1];
    loop(i, 0, n) {
        ReadPositiveInt(&a[i].ss);
        a[i].ff = i;
    }
    a[n].ss = 0;
    radix_sort(a, n + 1);
    int b[n], cnts = -1;
    loop(i, 1, n + 1) {
        if (a[i - 1].ss != a[i].ss) {
            cnts++;
        }
        b[a[i].ff] = cnts;
    }
    
    bool take[n] = {0};
    int l = -1, r;
    int ans = 0, tmp_ans = 0;
    for (r = 0; r < n; r++) {
        if (take[b[r]]) {
            l++;
            for (; l < n ; l++) {
                take[b[l]] = false;
                tmp_ans--;
                if (b[l] == b[r]) break;
            }
        }
        take[b[r]] = true;
        tmp_ans++;
        if (tmp_ans > ans) ans = tmp_ans;
    }
    PutInt(ans);
    OutputFlush();
}