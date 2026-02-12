echo "Enter number "
read a 
count= 0

while [ $a -gt 0 ]
do
	count=`expr $count + 1`
	a=`expr $a / 10`
done
echo "$count"

