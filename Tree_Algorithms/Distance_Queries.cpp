input/code.cpp: In function 'void set_parent(int, int, int)':
input/code.cpp:31:35: warning: comparison of integer expressions of different signedness: 'std::vector<int>::size_type' {aka 'long unsigned int'} and 'int' [-Wsign-compare]
   31 |         if (Parent[parent].size() < curr) break;
      |             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~
input/code.cpp: In function 'int get_parent(int, int)':
input/code.cpp:48:38: warning: comparison of integer expressions of different signedness: 'std::vector<int>::size_type' {aka 'long unsigned int'} and 'int' [-Wsign-compare]
   48 |             if(Parent[parent].size() < curr){
      |                ~~~~~~~~~~~~~~~~~~~~~~^~~~~~
input/code.cpp:43:9: warning: unused variable 'm' [-Wunused-variable]
   43 |     int m = 0;
      |         ^