g++ ising2d.cpp
start=`date +%s`
for t in {1..500..1}
do
./a.out $t 0 > $t.dat
done  
end=`date +%s`
echo Time execution: $((end-start)) seg
