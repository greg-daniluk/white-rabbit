#!/usr/bin/python
import sys
import math
import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter

POINTS = 10000
INIT_LAT = 49970
STEP = 100
ALPHA = 2.57302194425528e-4

lat = []
for i in range(0, POINTS-1):
	lat.append(INIT_LAT+i*STEP)

#calculate pps skew for latencies
skew = []
for i in range(0, POINTS-1):
	skew.append(lat[i]*ALPHA/2/(2+ALPHA))

#calculate pps factor
dalds = []
for i in range(0, POINTS-1):
	dalds.append( (lat[i]/(0.5*lat[i]-skew[i])**2)**2 )

#draw graph of dalds
fig = plt.figure(0)
plt.title("dalds(latency)")
ax1 = fig.add_subplot(111)
ax1.plot(range(0, POINTS-1), dalds, marker='.', linestyle='None', c='b', scaley=True, scalex=False)
ax1.set_xlim([0, POINTS-1])
plt.show()

print "dalds[0]=" + str(dalds[0])
