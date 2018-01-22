from random import randint
f=open("1990.in","w")
n=80
m=200
f.write("%d %d\n" %(n,m))
p=randint(1,10)
f.write("%d " %(p))
for i in range(n-1):
    p=randint(p,p+randint(0,3))
    f.write("%d " %(p))
f.write("\n")
for i in range(m):
    p=randint(1,2)
    if p==1:
        f.write("%d %d\n" %(randint(1,n),1))
    if p==2:
        f.write("%d %d\n" %(randint(1,n),-1))
f.close()


            
