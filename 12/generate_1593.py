from random import randint
fhand=open("1593.in","w")
n=50000
r=50
fhand.write("%d %d\n"%(n,r))
for i in range(n):
	fhand.write("%d "%randint(0,10000))
fhand.write("\n")
for i in range(n):
	fhand.write("%d "%randint(0,10000))
fhand.write("\n")
fhand.close()