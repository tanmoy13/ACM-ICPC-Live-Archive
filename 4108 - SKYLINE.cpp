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
#define MOD              1000000007
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
#define loop1(i,n)       for(int i=1;i<=n;i++)
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

#define mx 100005

struct data
{
    ll maxi, mini, prop;

};

struct inp
{
    int l, r, v;
    inp(int a, int b, int c)
    {
        l=a,r=b,v=c;
    }
};

data tree[mx*4];

int ls,rs,h;

void push_down(int n)
{
    int val=tree[n].prop;
    if(tree[n].prop!=0)
    {
        tree[n*2].prop=val;
        tree[n*2+1].prop=val;
        tree[n*2].maxi=val;
        tree[n*2+1].maxi=val;
        tree[n*2].mini=val;
        tree[n*2+1].mini=val;
        tree[n].prop=0;
    }
}

void push_up(int n)
{
    tree[n].maxi=max(tree[n*2].maxi,tree[n*2+1].maxi);
    tree[n].mini=min(tree[n*2].mini,tree[n*2+1].mini);
}

int anss=0;

void update(int n, int b, int e, int i, int j)
{
    if(b>j || e<i) return;
    if(b>=i && e<=j)
    {
        if(tree[n].maxi<h)
        {
            tree[n].maxi=h;
            tree[n].prop=h;
            tree[n].mini=h;
            return;
        }
        else if(tree[n].mini>h)
        {
            anss+=(e-b+1);
            return;
        }
    }
    if(b==e) return;
    push_down(n);
    int l=n*2;
    int r=l+1;
    int mid=(b+e)/2;
    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);
    push_up(n);
}

int main()
{

    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    int n;
    sf(t);
    {
        TEST_CASE(t)
        {
            sf(n);
            ll ans=0;

            ms(tree,0);

            vector<inp>vv;
            int rss=0;
            loop(i,n)
            {

                sfff(ls,rs,h);
                rss=max(rss,rs);
                vv.pb(inp(ls,rs,h));
            }

            for(int i=0; i<n; i++)
            {
                ls=vv[i].l;
                rs=vv[i].r;
                h=vv[i].v;
                anss=0;
                update(1,1,rss+3,ls,rs-1);
                ans+=(rs-ls-anss);

            }
            pf("%lld\n",ans);
        }
    }

    sf(t);

    return 0;
}


