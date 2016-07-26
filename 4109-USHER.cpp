/*
     If opportunity doesn't knock, build a door.

            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
            |S|.|S|.|R|.|A|.|S|.|A|.|M|.|K|
            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    Success is how high you bounce when you hit bottom.
*/


#include <bits/stdc++.h>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define D(x)             cout<<#x " = "<<(x)<<endl
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              10000019
#define CIN              ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define loop(i,n)        for(int i=0;i<n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))

using namespace std;


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

vector<int>graph[505],cost[505];
int cap,p,usernum;

int aa=INT_MAX;

int bfs(int src, int dst)
{
    int dis[505];
    for(int i=0;i<505;i++) dis[i]=infinity;
    dis[src]=0;
    queue<int>Q;
    Q.push(src);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<SZ(graph[u]);i++)
        {
            int v=graph[u][i];
            if(dis[u]+cost[u][i]<dis[v])
            {
                dis[v]=dis[u]+cost[u][i];
                Q.push(v);
            }
        }
    }
    return dis[dst];
}



int main()
{

//     freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);


    int t;
    while(sf(t)==1 && t)
    {
        TEST_CASE(t)
        {
//            D(z);
            for(int i=0;i<505;i++)
            {
                graph[i].clear();
                cost[i].clear();
            }
            sff(cap,p);
            vector<int>user;
            sf(usernum);
            loop(i,usernum)
            {
                int a;
                sf(a);
                user.pb(a);
            }

            for(int i=1;i<=p;i++)
            {
                int xx;
                sf(xx);
                for(int j=1;j<=xx;j++)
                {
                    int a,b;
                    sff(a,b);
                    graph[i].pb(b);
                    cost[i].pb(a);
                }
            }

            aa=INT_MAX;

            for(int i=0;i<SZ(user);i++)
            {
                aa=min(aa,bfs(user[i],0));
            }

            if(aa==0)
            {
                pf("0\n");
                continue;
            }

            {
                int sum=0;
                int ans=0;
                sum=0;
                while(sum<cap)
                {
                    sum+=(aa);
                    if(sum>=cap) break;
                    sum--;
                    ans++;
                }
                pf("%d\n",ans);
            }


        }
    }
    return 0;
}

