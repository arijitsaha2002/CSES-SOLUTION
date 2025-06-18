input/code.cpp: In function 'long int MinDist(long int, long int)':
input/code.cpp:48:23: warning: comparison of integer expressions of different signedness: 'long int' and 'std::vector<std::pair<long int, long int> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   48 |     for (int k = 0; k < V.size(); k++) {
      |                     ~~^~~~~~~~~~
input/code.cpp:49:31: warning: comparison of integer expressions of different signedness: 'long int' and 'std::vector<std::pair<long int, long int> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   49 |         for (int l = k + 1; l < V.size() and (V[l].first - V[k].first) * (V[l].first - V[k].first) < d; l++) {
      |                             ~~^~~~~~~~~~