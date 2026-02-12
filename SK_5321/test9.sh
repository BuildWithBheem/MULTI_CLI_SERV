read num1
read num2

read Op

if [ $Op -eq 1 ]
then
	sum=`expr $num1 + $num2`
	echo "sum is $sum"
elif [ $Op -eq 2 ]
then
	diff=`expr $num1 - $num2`
	echo "Diff is $diff"
elif [ $Op -eq 3 ]
then
	mul=`expr $num1 \* $num2`
	echo "Product is $mul"
elif [ $Op -eq 4 ]
then
        div=`expr $num1 % $num2`
	echo "The remainder is $div"
else
	echo "Invalid operation"
fi

