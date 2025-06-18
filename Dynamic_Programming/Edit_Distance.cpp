input/code.cpp: In function 'int main()':
input/code.cpp:25:23: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<unsigned int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   25 |     for (int i = 0; i < Table.second->size(); i++) {
      |                     ~~^~~~~~~~~~~~~~~~~~~~~~
input/code.cpp:30:23: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   30 |     for (int i = 1; i <= A.size(); i++) {
      |                     ~~^~~~~~~~~~~
input/code.cpp:32:27: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<unsigned int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   32 |         for (int j = 1; j < Table.first->size(); j ++) {
      |                         ~~^~~~~~~~~~~~~~~~~~~~~