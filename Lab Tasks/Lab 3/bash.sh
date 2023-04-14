echo "Hello From Bash"
myvar=Hello
echo $myvar
myvar="Yes sir!"
echo $myvar
myvar=7+5
echo $myvar
echo 1st Argument : $1
echo 3rd Argument : $3
echo Argument : $1
shift
echo Arugmment : $1
shift
echo Argument : $1


if [ $#-gt0 ]; then
echo "Your Command Line contains $# arguments"
echo "All arguments displayed using \$ * Positional parameter"
else
echo "Your Command Line contains $# arguments"
fi

echo "Your 1st Name Please: "
read fiLe
echo "Hello $fiLe , Let us be Friend!"

count=100

if [ $count-eq100 ];then
echo "count is 100"
fi

if[ $test $-gt0 ];then
echo "$1 number is positive"
fi
