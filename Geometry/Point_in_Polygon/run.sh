g++ "$1"
./a.out < "$2" > myoutput
diff "$3" myoutput | head -3