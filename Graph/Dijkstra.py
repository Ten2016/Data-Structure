'''
    最短路径算法: 
'''

import numpy as np
import matplotlib.pyplot as plt
import math


NUM=20      # 数据个数
MAX=999     # INf
np.random.seed(11)   # 固定随机种子
# 随机生成坐标
x=np.random.randint(15,85,(1,NUM))
y=np.random.randint(15,85,(1,NUM))
w=np.zeros((NUM,NUM),dtype=int)  # 距离记录
p=np.zeros((NUM,NUM),dtype=int)  # 路径记录
# 距离和路径初始化
for i in range(NUM):
    for j in range(i,NUM):
        dist=(x[0][j]-x[0][i])**2+(y[0][j]-y[0][i])**2
        if dist>600:    # 舍弃一些路径
            w[j][i]=w[i][j]=MAX
            continue
        w[i][j]=round(math.sqrt(dist))
        w[j][i]=w[i][j]
        p[i][j]=j   # 采用正向记录
        p[j][i]=i

# 显示初始状态
plt.plot(x,y,'or')  # 绘制所有的点
for i in range(NUM):
    for j in range(i,NUM):
        if i==j:    # 对点进行编号
            plt.text(x[0][i],y[0][i],i+1,fontsize=10,color='g')
        if(w[i][j]!=MAX):
            xi=[x[0][i],x[0][j]]
            yi=[y[0][i],y[0][j]]
            plt.plot(xi,yi,'b',linewidth=1)

# Floyd 算法核心
for k in range(NUM):
    for i in range(NUM):
        for j in range(NUM):
            if(w[i][j]>w[i][k]+w[k][j]):
                w[i][j]=w[i][k]+w[k][j]
                p[i][j]=p[i][k]


# 显示最短路径
fr,to = 16,18   # 16到18
while fr!=to:
    frt=p[fr][to]   # 得到下一个点
    xi=[x[0][fr],x[0][frt]]
    yi=[y[0][fr],y[0][frt]]
    plt.plot(xi,yi,color='black',linewidth=5)
    fr=frt
xi=[x[0][fr],x[0][to]]
yi=[y[0][fr],y[0][to]]
plt.plot(xi,yi,color='black',linewidth=5)
plt.show()



if __name__ == "__main__":
    pass

