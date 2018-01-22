n=input()
 #0 -> 1 down 2<- 3 up
up=0
down=n-1
left=0
right=n-1
cnt=1
loc=[0,-1]
mat=[[0 for i in range(n)] for i in range(n)]
for i in range(2*n-1):
    if i%4==0:
        up+=1
        while loc[1]<right:
            loc[1]+=1
            mat[loc[0]][loc[1]]=cnt
            cnt+=1
    if i%4==1:
        right-=1
        while loc[0]<down:
            loc[0]+=1
            mat[loc[0]][loc[1]]=cnt
            cnt+=1
    if i%4==2:
        down-=1
        while loc[1]>left:
            loc[1]-=1
            mat[loc[0]][loc[1]]=cnt
            cnt+=1
    if i%4==3:
        left+=1
        while loc[0]>up:
            loc[0]-=1
            mat[loc[0]][loc[1]]=cnt
            cnt+=1
for i in mat:
    for num in i:
        print "%6d"%num,
    print
            
