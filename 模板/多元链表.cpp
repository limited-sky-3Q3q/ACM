

//ͼ�۳���
int head[MAXN],len=1;
struct edge{
    ll v,w,next;
}e[2*MAXN];//*����ͼͨ����Ҫ�����ֵ��*2

//�ӱ�
void add(ll u, ll v, ll w){
    e[len].v=v;
    e[len].w=w;
    e[len].next=head[u];
    head[u]=len++;
}

//����
for(int i=head[n]; i>0; i=e[i].next){
    //n:��n������
    //i = head[n]:��n�������ͷָ��
    //e[i]Ϊ��Ӧ�ıߣ�����
}