#include <iostream>
#include <queue>
using namespace std;

int n,visit[26][26]={0,};
int cnt=0;
int apart[26][26]={0,};
queue<pair<int,int>>q;
int part[26];

int bfs(int n){
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            if(apart[i][k]==1&&visit[i][k]==0){
                cnt++;
                part[cnt]++;
                q.push(make_pair(i,k));
                while(!q.empty()) {
                    visit[i][k] = 1;
                    pair<int, int> p = q.front();
                    q.pop();
                    int x=p.first;
                    int y=p.second;
                    if(apart[x+1][y]==1&&visit[x+1][y]==0){
                        visit[x+1][y]=1;
                        part[cnt]++;
                        q.push(make_pair(x+1,y));
                    }
                    if(apart[x-1][y]==1&&visit[x-1][y]==0){
                        visit[x-1][y]=1;
                        part[cnt]++;
                        q.push(make_pair(x-1,y));

                    }
                    if(apart[x][y+1]==1&&visit[x][y+1]==0){
                        visit[x][y+1]=1;
                        part[cnt]++;
                        q.push(make_pair(x,y+1));

                    }
                    if(apart[x][y-1]==1&&visit[x][y-1]==0){
                        visit[x][y-1]=1;
                        part[cnt]++;
                        q.push(make_pair(x,y-1));

                    }
                }
            }
        }
    }
}
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            cin>>apart[i][k];
        }
    }
    bfs(n);
    cout<<cnt<<endl;
    int n = sizeof(part)/sizeof(part[0]);
    radixsort(part, n);

    for(int i=26-cnt;i<26;i++){
        cout<<part[i]<<endl;
    }
    return 0;
}