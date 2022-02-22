

//图论常用
int head[MAXN],len=1;
struct edge{
    ll v,w,next;
}e[2*MAXN];//*无向图通常都要在最大值后*2

//加边
void add(ll u, ll v, ll w){
    e[len].v=v;
    e[len].w=w;
    e[len].next=head[u];
    head[u]=len++;
}

//遍历
for(int i=head[n]; i>0; i=e[i].next){
    //n:第n个链表
    //i = head[n]:第n个链表的头指针
    //e[i]为相应的边，有向
}