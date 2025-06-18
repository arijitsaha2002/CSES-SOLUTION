input/code.cpp: In function 'void set_parent(int, int, int)':
input/code.cpp:30:35: warning: comparison of integer expressions of different signedness: 'std::vector<int>::size_type' {aka 'long unsigned int'} and 'int' [-Wsign-compare]
   30 |         if (Parent[parent].size() < curr) break;
      |             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~
input/code.cpp: In function 'int get_parent(int, int)':
input/code.cpp:47:38: warning: comparison of integer expressions of different signedness: 'std::vector<int>::size_type' {aka 'long unsigned int'} and 'int' [-Wsign-compare]
   47 |             if(Parent[parent].size() < curr){
      |                ~~~~~~~~~~~~~~~~~~~~~~^~~~~~
input/code.cpp:42:9: warning: unused variable 'm' [-Wunused-variable]
   42 |     int m = 0;
      |         ^