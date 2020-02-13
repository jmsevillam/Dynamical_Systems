g++ ising2d_field_off.cpp
start=`date +%s`
for t in {1..500..1}
do
./a.out $t 10 > $t.dat
done  
end=`date +%s`
echo Time execution: $((end-start)) seg
