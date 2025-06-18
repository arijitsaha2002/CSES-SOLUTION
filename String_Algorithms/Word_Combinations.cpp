input/code.cpp: In function 'long int dfs(std::string&, int)':
input/code.cpp:64:15: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   64 |     if (start == s.size()) return 1;
      |         ~~~~~~^~~~~~~~~~~
input/code.cpp:70:27: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   70 |     for (int i = start; i < s.size(); i ++) {
      |                         ~~^~~~~~~~~~