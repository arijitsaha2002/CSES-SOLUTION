g++ brute_force.cpp -o a
g++ code.cpp -o b


for i in {1..10000..1}; 
do 
    echo $i > input
    ./a < input > a.txt
    ./b < input > b.txt
    diff a.txt b.txt

done;