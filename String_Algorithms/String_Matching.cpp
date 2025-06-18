input/code.cpp: In function 'int main()':
input/code.cpp:15:14: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   15 |     while (i < s.size()) {
      |            ~~^~~~~~~~~~
input/code.cpp:22:35: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   22 |     for(int j = pattern.size(); j < s.size(); j++) i += (pi_array[j] == pattern.size());
      |                                 ~~^~~~~~~~~~
input/code.cpp:22:70: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   22 |     for(int j = pattern.size(); j < s.size(); j++) i += (pi_array[j] == pattern.size());
      |                                                          ~~~~~~~~~~~~...