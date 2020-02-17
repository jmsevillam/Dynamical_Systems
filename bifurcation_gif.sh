g++ pendulum3.cpp -o a3.out
for i in `seq 0 0.05 2`
do
    time ./a3.out 1 30000 10000 $i > plots/data_bif_nD$i.dat
    echo $i
done

python3 plots_bifurcation_gif.py
