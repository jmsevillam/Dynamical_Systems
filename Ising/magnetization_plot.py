import numpy as np
import os
import matplotlib.pylab as plt
for _,_,filenames in os.walk("."):
    break
files=[name[:-4] for name in filenames if name.endswith('dat')]
print(files[:50])
M=[]
chi=[]
T=[]
for i in files:
    data=np.genfromtxt(i+'.dat')
    M.append(np.mean(data))
    chi.append((np.var(data))/((float(i)/100)**2))
    T.append(float(i)/100)
plt.plot(T,np.abs(M))
plt.ylabel('Magnetization $|<M>|$')
plt.xlabel('Temperature $k_BT$')
plt.show()
plt.plot(T,chi)
plt.ylabel('Susceptibillity $\chi$')
plt.xlabel('Temperature $k_BT$')
plt.show()
