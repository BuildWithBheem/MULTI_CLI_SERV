read a
read b

temp=`expr $a + $b`
a=`expr $temp - $a`
b=`expr $temp - $b`

echo "After swap : $a , $b"

