#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>lis;
vector<int>lds;
int num_train;

int lis_result(int point,vector<int>v){
    vector<int>tmp;
    int ret=1;
    tmp.push_back(v[point]);
    int i=0;
    for(i=point+1;i<num_train;i++){
        if(tmp[0]<v[i]) {
            tmp.push_back(v[i]);
            ret++;
            i++;
            break;
        }
    }

    for(i;i<num_train;i++){
        if(tmp[0]>v[i])
            continue;
        if(lis.back()<v[i]) {
            lis.push_back(v[i]);
            ret++;
        }
        else{
            auto pos=lower_bound(tmp.begin(),tmp.end(),v[i]);
            *pos=v[i];
        }
    }
    return ret;
}

int getLds(vector<int> lds, int start, int end, int target)
{
    int mid;

    while (start < end)
    {
        mid = (start + end) / 2;

        if (lds[mid] > target)
            start = mid + 1;
        else
            end = mid;
    }
    return end + 1;
}

int lds_result(int here, vector<int> vc)
{
    vector<int> lds;
    int plds = 1;

    // 현재 idx값 고정
    lds.push_back(vc[here]);

    int i = 0;
    for (i = here + 1; i < num_train; i++)
        if (lds[0] > vc[i])
        {
            lds.push_back(vc[i]);
            plds++;
            i++;
            break;
        }

    for (i; i < num_train; i++)
    {
        // 현재 idx값보다 큰 값이 나타나면 현재 기준 lis에 모순이 일어나기에 continue
        if (lds[0] < vc[i])
            continue;

        if (lds.back() > vc[i])
        {
            lds.push_back(vc[i]);
            plds++;
        }

        else
        {
            int pos = getLds(lds, 1, plds, vc[i]);
            lds[pos - 1] = vc[i];
        }

    }

    return plds;
}
int main() {
    int result=10000000;
    vector<int>l;//list of train weight
    cin>>num_train;
    for(int i=0;i<num_train;i++){
        int tmp;
        cin>>tmp;
        l.push_back(tmp);
    }
    for(int i=1;i<num_train;i++){
        int li=lis_result(i,lis);
        int ld=lds_result(i,lds);
        if(result>li+ld-1)
            result=li+ld-1;
    }
    cout<<result;
    return 0;
}