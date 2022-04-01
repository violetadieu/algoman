import sys

def solution(n,k):
    result=0
    DP=[[0 for col in range(k+1)]for row in range(n)]
    weight=list()
    value=list()

    for idx in range(n):
        w,v=map(int,sys.stdin.readline().split())
        weight.append(w)
        value.append(v)

    for idx in range(n):
        for wei in range(k+1):
            if wei>=weight[idx]:
                DP[idx][wei]=max(DP[idx-1][wei],DP[idx-1][wei-weight[idx]]+value[idx])
            else:
                DP[idx][wei]=DP[idx-1][wei]

    print(DP[n-1][k])

    return result



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    n,k=map(int,sys.stdin.readline().split())
    solution(n,k)
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
