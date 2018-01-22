from random import randint
fhand=open("2106.in","w")
n=randint(50,100)
m=randint(50,100)
fhand.write("%d %d\n"%(n,m))
for i in range(n):
    for j in range(m):
        fhand.write("%d "%randint(0,1000))
    fhand.write("\n")
fhand.write("\n")
for i in range(n):
    for j in range(m):
        fhand.write("%d "%randint(0,100))
    fhand.write("\n")
ss=set()
a=randint(1,n)
b=randint(1,m)
fhand.write("%d %d "%(a,b))
ss.add((a,b))
for i in range(2):
    a=randint(1,n)
    b=randint(1,m)
    while (a,b) in ss:
        a=randint(1,n)
        b=randint(1,m)
    ss.add((a,b))
    fhand.write("%d %d "%(a,b))
fhand.close()
            
