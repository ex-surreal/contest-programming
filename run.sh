[ -z $1 ] && exit 1
filename=`basename $1`
g++ $1 --std=c++14 -I ./include -Wall -Wextra -Werror -o ./bin/$filename.o && ./bin/$filename.o
