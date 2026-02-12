echo "Enter number"
read a
i=$a
unit=`expr $a % 10`
while [ $a -gt 0 ] 
do
	i=$a
	a=`expr $a / 10`
done
diff=`expr $unit - $i`

echo "Diff is : $diff"
