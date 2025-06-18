input/code.cpp: In function 'void set_parent(int, int)':
input/code.cpp:28:35: warning: comparison of integer expressions of different signedness: 'std::vector<int>::size_type' {aka 'long unsigned int'} and 'int' [-Wsign-compare]
   28 |         if (Parent[parent].size() < curr) break;
      |             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~
input/code.cpp: In function 'int get_parent(int, int)':
input/code.cpp:45:38: warning: comparison of integer expressions of different signedness: 'std::vector<int>::size_type' {aka 'long unsigned int'} and 'int' [-Wsign-compare]
   45 |             if(Parent[parent].size() < curr){
      |                ~~~~~~~~~~~~~~~~~~~~~~^~~~~~
input/code.cpp:40:9: warning: unused variable 'm' [-Wunused-variable]
   40 |     int m = 0;
      |         ^