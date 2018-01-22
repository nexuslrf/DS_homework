from random import randint
f=open("1056.in","w")
n=40
f.write("%d %d\n"%(n,100))
for i in range(100):
    p=randint(1,3)
    if p==1:
        f.write("%s %d %d\n"%('C',randint(1,n),randint(1,n)))
    if p==2:
        f.write("%s %d\n"%('D',randint(1,n)))
    else:
        f.write("%s %d\n"%('Q',randint(1,10)))
f.close()
          
