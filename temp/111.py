'''
TODO Auther: by SR
FilePath: \digital designc:\Users\SR\Documents\vscodefile\temp\111.py
Date: 2020-10-05 20:03:34
LastEditTime: 2020-10-05 20:03:38
!今日运势: 吉，无bug
'''
def time(elem):
    return elem[3]
n,m = map(int,input().split())
dic={}
for i in range(n):
    s=input()
    dic[s]=i
# print(dic)
cach=[]
for i in range(m):
    s=input()
    s=s.split(",")
    if(s[2]=="win"):
        t=s[3].split(":")
        s[3]=int(t[0])*60+int(t[1])
        cach.append(s)
cach.sort(key=time)
# print(cach)
for i in range(len(cach)):
    s=cach[i]
    pre=dic[s[0]]
    aft=dic[s[1]]
    dic[s[0]]=min(pre,aft)
    dic[s[1]]=max(pre,aft)
ans=[None]*(n+10)
for item in dic:
    ans[dic[item]]=item
for i in range(n):
    print(ans[i])