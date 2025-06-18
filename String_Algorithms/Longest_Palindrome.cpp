input/code.cpp: In function 'int main()':
input/code.cpp:37:14: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   37 |     while (i < str.size()) {
      |            ~~^~~~~~~~~~~~
input/code.cpp:43:30: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   43 |         while (i + dp[i] + 1 < str.size() and i > dp[i] and str[i - dp[i] - 1] == str[i + dp[i] + 1]) {
      |                ~~~~~~~~~~~~~~^~~~~~~~~~~~