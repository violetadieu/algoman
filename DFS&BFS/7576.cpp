#include <stdio.h>
#include <queue>
using namespace std;

int tomato[1000][1000], visit[1000][1000], m, n;
int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
int cnt, size, x, y, xx, yy;

struct col {
    int x, y;
};
queue<col> que;

int bfs() {
    int ans = 1;
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            col c1 = que.front();
            que.pop();
            x = c1.x, y = c1.y;

            if (visit[x][y])
                continue;
            else
                visit[x][y] = 1;

            for (int j = 0; j < 4; ++j) {
                xx = x + dir[j][0];
                yy = y + dir[j][1];

                if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                    continue;
                else if (tomato[xx][yy] == -1)
                    continue;

                else if (tomato[xx][yy] == 0) {
                    que.push({ xx,yy });
                    tomato[xx][yy] = 1;
                    cnt--;
                }

                if (cnt == 0)
                    return ans;
            }
        }
        ans++;
    }
    return -1;
}

int main() {
    scanf("%d %d", &m, &n);
    int tmp=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &tomato[i][j]);

            if (tomato[i][j] == 1)
                que.push({ i,j });
            else if (tomato[i][j] == 0)
                cnt++;
        }
    }
    for(int i=0;i<n;i++) {
        if(tmp!=0)
            break;
        for(int k=0;k<m;k++) {
            if(tomato[i][k]==0)
                tmp++;
        }
    }
    if(tmp==0){
        printf("0");
        return 0;
    }
    else
        printf("%d", bfs());
    return 0;
}
