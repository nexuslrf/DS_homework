a=[0]*51
b=[0]*51
dp=[a,b]
s=raw_input()
s=s.split()
k=eval(s[0])
h=eval(s[1])
for hx in range(2,h+1):
    for i in range(k):
        if hx==2:
            dp[hx%2][i]=k-i
        else:
            dp[hx%2][k-i-1]=dp[hx%2][k-i]+dp[(hx-1)%2][i]
#print dp
print dp[h%2][0]
            
        
