import numpy as np
import os
import matplotlib.pylab as plt
for _,_,filenames in os.walk("."):
    break
files=[int(name[:-6]) for name in filenames if (name.endswith('dat') and '-' in (name))]

M=[]
chi=[]
T=[]
for i in np.unique(files):
    mag=0
    sus=0
    temp=0
    for j in range(10):
        data=np.genfromtxt(str(i)+'-'+str(j)+'.dat')
        mag+=(np.abs(np.mean(data)))
        sus+=((np.var(data))/((i/100)**2))
    M.append(mag/10)
    chi.append(sus/10)
    T.append(i/100)
    
T, chi, M = (list(l) for l in zip(*sorted(zip(T, chi, M))))

plt.plot(T,np.abs(M))
plt.ylabel('Magnetization $|<M>|$')
plt.xlabel('Temperature $k_BT$')
plt.show()


plt.plot(T,chi)
plt.ylabel('Susceptibillity $\chi$')
plt.xlabel('Temperature $k_BT$')
plt.show()
