import sys

def solution(n):
    result=0
    triangle=list()
    triangle=[[0 for col in range(n+1)] for row in range(n+1)]
    DP=[[0 for col in range(n+1)] for row in range(n+1)]

    for i in range(n):
        triangle[i]=list(map(int,sys.stdin.readline().split()))

    DP[0][0]=triangle[0][0]
    DP[1][0]=DP[0][0]+triangle[1][0]
    DP[1][1]=DP[0][0]+triangle[1][1]

    for layer in range(2,n):
        for idx in range(layer+1):
            if idx == 0:
                DP[layer][idx]=triangle[layer][idx]+DP[layer-1][0]
            elif idx == layer:
                DP[layer][idx]=triangle[layer][idx]+DP[layer-1][idx-1]
            else:
                DP[layer][idx]=triangle[layer][idx]+max(DP[layer-1][idx],DP[layer-1][idx-1])


    for i in range(n):
        result=max(result,DP[n-1][i])

    return result



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    n=int(input())
    print(solution(n))
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
