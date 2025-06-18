input/code.cpp: In function 'int main()':
input/code.cpp:27:36: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   27 |     for(int i = 1, l = 0, r = 0; i < str.size(); i++){
      |                                  ~~^~~~~~~~~~~~
input/code.cpp:29:24: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   29 |         while(i + z[i] < str.size() and str[z[i]] == str[i + z[i]]) z[i] ++;
      |               ~~~~~~~~~^~~~~~~~~~~~
input/code.cpp:33:22: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   33 |     for(int i = 1; i < str.size(); i++){
      |                    ~~^~~~~~~~~~~~
input/code.cpp:34:21: warning: comparison of integer...