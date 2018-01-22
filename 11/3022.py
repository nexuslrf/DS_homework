a=2
b=4
c=7
n=input()
for i in range(n-3):
    ans=a+b+c
    a=b
    b=c
    c=ans
print ans
