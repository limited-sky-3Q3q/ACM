'''
@TODO Auther: by SR
@FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200607\I.py
@Date: 2020-06-07 16:15:59
@LastEditTime: 2020-06-08 11:08:31
@!今日运势: 吉，无bug
'''
(n, k) = map(int, input().split())
arr = []
def takeSecond(elem):
    return elem[1]
for i in range(n):
    (name, num) = input().split()
    arr.append((name, int(num)))
arr.sort(key = takeSecond, reverse = True)
ans = []
for i in range(n):
    if k >= arr[i][1]:
        k = k - arr[i][1]
        ans.append(arr[i][0])
if k == 0:
    print(len(ans))
    for i in range(len(ans)):
        print(ans[i])
else:
    print(0)