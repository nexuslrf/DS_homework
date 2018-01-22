from random import randint
import numpy as np
fhand=open("1999.in","w")
m=30
n=30
fhand.write("%d %d\n"%(n,m))
maze=np.zeros((n+1,m+1),dtype=int)
maze-=1
maze[randint(1,n)][randint(1,m)]=2
for i in range(4):
    x=randint(1,n)
    y=randint(1,m)
    while maze[x][y]!=-1:
        x=randint(1,n)
        y=randint(1,m)
    maze[x][y]=1
for i in range(700):
    x=randint(1,n)
    y=randint(1,m)
    while maze[x][y]!=-1:
        x=randint(1,n)
        y=randint(1,m)
    maze[x][y]=0
for i in range(1,n+1):
    for j in range(1,m+1):
        fhand.write("%d\t"%maze[i][j])
    fhand.write("\n")
fhand.close()



            
