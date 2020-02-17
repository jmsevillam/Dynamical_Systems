import os
import numpy as np
import matplotlib.pylab as plt

for _,_,files in os.walk('plots/.'):
    break
files=[i for i in files if (("data_bif" in i) and (".dat" in i))]
print(files)
for i in files:
    print(i) 
    fil=i.split('D')[1][:-4]
    print(fil)
    data= np.genfromtxt("plots/"+i).T
    
    q=data[1]
    F=data[-1]

    plt.plot(F,np.mod(q+np.pi,2*np.pi)-np.pi,'.k',markersize=0.2)
    plt.title("$\gamma=$"+str(fil))
    plt.ylim(top=np.pi,bottom=-np.pi)
    plt.xlabel("Force $F$")
    plt.ylabel("Angle $\\theta$")
    plt.savefig("plots/"+fil+".png")
    plt.close()
