/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200419\E.cpp
 * Date: 2020-04-19 12:50:25
 * LastEditTime: 2020-04-19 13:29:58
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

int main(){
    int n,p;
    char que[100], *ptr,DE;
    const int DD=8*60*60 + 30*60,ED=12*60*60 + 30*60;//上班时间
    int time[20];
    while(cin>>n){
        if(n==0)break;

        memset(time, 0, sizeof time);
        p=0;
        getchar();
        for(int i=0; i<n; i++){
            cin.getline(que, 100);
            
            ptr = strtok(que, ":");
            DE=ptr[0];

            //or(int j=0; j<3; j++){//上班时间
            //h
            ptr=strtok(NULL, ":");
            if(strlen(ptr)==1){
                time[0]=ptr[0]-'0';
            }
            else{//2
                time[0]=(ptr[0]-'0')*10 + (ptr[1]-'0');
            }
            
            ptr=strtok(NULL, ":");
            time[1]=(ptr[0]-'0')*10 + (ptr[1]-'0');
            ptr=strtok(NULL, ":");
            time[2]=(ptr[0]-'0')*10 + (ptr[1]-'0');
            
            //h2
            ptr=strtok(NULL, ":");
            if(strlen(ptr)==1){
                time[3]=ptr[0]-'0';
            }
            else{//2
                time[3]=(ptr[0]-'0')*10 + (ptr[1]-'0');
            }

            ptr=strtok(NULL, ":");
            time[4]=(ptr[0]-'0')*10 + (ptr[1]-'0');
            ptr=strtok(NULL, "\0");//s2
            time[5]=(ptr[0]-'0')*10 + (ptr[1]-'0');
            
        /************************************************************************************************/
            time[6]=time[0]*60*60 + time[1]*60+time[2];
            time[7]=time[3]*60*60 + time[4]*60+time[5];

            if(DE=='D'){
                if(time[6]>9*60*60 + 30*60){//迟到
                    p++;
                    continue;
                }

                if(time[6]<8*60*60 + 30*60){//8:30
                    time[6]=8*60*60 + 30*60;
                }
                
                if(time[7]-time[6]<8*60*60){//时间不够
                    p++;
                    continue;
                }

            }
            else{//E
                if(time[6]>12*60*60 + 30*60){//迟到
                    p++;
                    continue;
                }

                if(time[6]<8*60*60 + 30*60){//8:30
                    time[6]=8*60*60 + 30*60;
                }
                
                if(time[7]-time[6]<9*60*60){//时间不够
                    p++;
                    continue;
                }
            }
            
        }
        if(p==0)
            cout<<"All OK\n";
        else if(p==1)
            cout<<"1 Point(s) Deducted\n";
        else if(p==2)//傻了。。
            cout<<"2 Point(s) Deducted\n";
        else if(p==3)
            cout<<"3 Point(s) Deducted\n";
        else
            cout<<"Issue Show Cause Letter\n";

    }
	

	return 0;
}
