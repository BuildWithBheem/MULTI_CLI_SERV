read a
rev=0

while ((a > 0))
do
	rev=$(( a % 10 + rev * 10 )) 
	a=$(( a / 10 ))

done

echo "Reversed number : $rev"
