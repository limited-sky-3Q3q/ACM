/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\CF\643\C.cpp
 * Date: 2020-05-16 20:08:22
 * LastEditTime: 2020-05-24 12:06:09
 * !��������: ������bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

ll calcProgression(ll a, ll d, ll n){
    return (2ll*a + d*(n-1))*n/2;
}
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans = 0;
    for(int z = c; z <= d; z++){
        int minX = max(a, z - c + 1);
        if(minX > b)
            continue;

        int mid = z - b + 1;
        int start = c - max(b, z - minX + 1) + 1;//��С�Ŀ������㵱ǰ������X
        
        if(mid <= minX){//������ȡ��yֵ
            ans += 1ll * (c - b + 1) * (b - minX + 1);
        }else if(mid > b){//����������ȡ��yֵ���Ȳ�����
            ans += calcProgression(start, 1, b - minX + 1);
        }else{//�����������
            ans += calcProgression(start, 1, mid - minX + 1);
            ans += 1ll * (c - b + 1) * (b - mid);
        }
        
    }
    cout<<ans;
    return 0;
}





//int que[4],ans;
//int main(){
    /*
    ans = 0;

    for(int i=0; i<4; i++)
        cin>>que[i];
    
   // ans = min(que[3], que[1] + que[2]) - max(que[0] + que[1] ,que[2]);
    
    int r = min(que[3], que[1] + que[2]);
    int l = min(que[2], que[0] + que[1]);

    if(que[3] >= que[0] + que[1]){
        ans = (r-l+1)*(l+r)/2;
    }
    else{
        ans = (que[3] - que[2] + 1)
    }
    
    
    cout<<ans;
    //cout<<ans;
	return 0;
    */


    //�ù�ʽ��
    /*
    int A, B, C, D;
    cin>>A>>B>>C>>D;
    ll ans = 0;
    for(int z = C; z <= D; z++){//���μ���z = [C, D] ʱ�Ŀ�������
        int minX = max(A, z - C + 1);//��ʱx����С��� x + C = z + 1
        if (minX > B)//������
            continue;
        

        //��������������������������������
        int mid = z - B + 1;//y ����ȡ B ʱ x ����Сֵ
        //                x ��Сʱ y �Ĵ�С
        int start = C - max(B, z - minX + 1) + 1;// x �Ŀ�ʼλ�� x >= 1


        if (mid <= minX){//x,y ȡ����ֵ����������
            ans += 1ll * (C - B + 1) * (B-minX +1);
        }else if(mid > B){//�� x = B ʱ y ��Ȼ����ȡ B �� һ���Ȳ����У�����Ϊ1
            ans += calcProgression(start, B - minX + 1);
        }else{//�����Ϸ��������֮�䣬�ֳ�������
            ans += calcProgression(start, mid - minX + 1);
            ans += 1ll*(B-mid)*(C-B+1);
        }
        cout<<ans<<"\n";
    }   
    
    return 0;
}
*/

//��ʽ�ⷨ
/*
ll calcProgression(ll a, ll d, ll n) {
    return (2 * a + d * (n - 1)) * n / 2;
}

void run() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    ll ans = 0;
    for (int z = c; z <= d; ++z) {
        int minX = std::max(a, z - c + 1);
        if (minX > b) {
            continue;
        }

        int mid = z - b + 1;
        int start = c - std::max(b, z - minX + 1) + 1;

        if (mid <= minX) {
            ans += 1ll * (c - b + 1) * (b - minX + 1);
        } else if (mid > b) {
            // ans += 1ll * (b - minX + 1) * (b - minX + 2) / 2;
            ans += calcProgression(start, 1, b - minX + 1);
        } else {
            ans += calcProgression(start, 1, mid - minX + 1);
            ans += 1ll * (b - mid) * (c - b + 1);
            // ans += 1ll * (mid - minX + 1) * (mid - minX + 2) / 2 + 1ll * (b - mid) * (c - b + 1);
        }
    }    

    printf("%lld\n", ans);
}

int main(void) {
    run();
    return 0;
}
*/


/*
ll calcProgression(ll a, ll d, ll n) {
    return (2 * a + d * (n - 1)) * n / 2;
}

void run() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    ll ans = 0;
    for (int z = c; z <= d; ++z) {
        int minX = std::max(a, z - c + 1);
        if (minX > b) {
            continue;
        }

        int mid = z - b + 1;
        int start = c - std::max(b, z - minX + 1) + 1;

        if (mid <= minX) {
            ans += 1ll * (c - b + 1) * (b - minX + 1);
        } else if (mid > b) {
            // ans += 1ll * (b - minX + 1) * (b - minX + 2) / 2;
            ans += calcProgression(start, 1, b - minX + 1);
        } else {
            ans += calcProgression(start, 1, mid - minX + 1);
            ans += 1ll * (b - mid) * (c - b + 1);
            // ans += 1ll * (mid - minX + 1) * (mid - minX + 2) / 2 + 1ll * (b - mid) * (c - b + 1);
        }
    }    

    printf("%lld\n", ans);
}

int main() {
    run();
    return 0;
}
*/