rm *.dat
g++ ising2d_average.cpp
start=`date +%s`
for t in `seq 1 1 500`
do
    for rep in `seq 0 1 9`
    do
        ./a.out $t 10 $rep > $t-$rep.dat
    done
done  
end=`date +%s`
echo Time execution: $((end-start)) seg
