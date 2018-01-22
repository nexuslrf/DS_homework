from random import randint
fhand=open("1232.in","w")
m=6
n=(m-1)*m/2
fhand.write("%d %d %d\n"%(m,randint(1,n),randint(1,n)))
for i in range(100):
    fhand.write("%d %d\n" %(randint(1,n),randint(0,3)))
fhand.close()
            
