#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <sstream>
#include <cstring>
using namespace std ;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define plii pair<pair<ll, int>, int>
#define piii pair<pii, int>
#define viii vector<pair<pii, int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)

#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)

#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)

#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)
#define ASST(x, l, r) assert( x <= r && x >= l )

const int mod = 1e9 + 7;

int ADD(int a, int b, int m = mod) {
    int s = a;
    s += b;
    if( s >= m )
      s -= m;
    return s;
}

int MUL(int a, int b, int m = mod) {
    return (1LL * a * b % m);
}

int power(int a, int b, int m = mod) {
    int res = 1;
    while( b ) {
        if( b & 1 ) {
            res = 1LL * res * a % m;
        }
        a = 1LL * a * a % m;
        b /= 2;
    }
    return res;
}

ll nC2(ll x) {
    return ( x * ( x - 1 ) / 2 );
}

const int maxn = 1e5 + 10;
const int limit = 1e6 + 10;
int n, A[maxn], P[limit], M[limit];
vi adj[limit];

void sieve() {
    int i, j;
    fr(i, 2, limit) {
        if( !P[i] ) {
            j = i;
            while( j < limit ) {
                P[j] = 1;
                adj[j].pb( i );
                j += i;
            }
        }
    }
}

class dsu {

    public :
    int n , max_component;
    vector<int> P , R , S;
    dsu(int n){
        this->n = n ;
        P.resize(n+1) ;
        R.resize(n+1) ;
        S.resize(n+1) ;
        for(int i=1;i<=n;i++){
            R[i] = 0 ;
            P[i] = i ;
            S[i] = 1 ;
        }
        max_component = 1 ;
    }

    int find(int x){
        if(x != P[x]){
            P[x] = find(P[x]) ;
        }
        return P[x] ;
    }

    bool add_edge(int x,int y){
        int rx , ry ;
        rx = find(x) ;
        ry = find(y) ;
        if(rx != ry){
            if(R[rx] < R[ry]){
                P[rx] = ry ;
                S[ry] += S[rx] ;
                max_component = max(max_component,S[ry]) ;
            }else{
                P[ry] = rx ;
                S[rx] += S[ry] ;
                max_component = max(max_component,S[rx]) ;
            }
            if(R[rx] == R[ry]){
                R[rx] ++ ;
            }
            return true ;
        }
        return false ;
    }

};

void solve(int testNo) {
    cin >> n;
    int i, j, cnt = 0, cnt1 = 0;
    vi p;
    fr(i, 1, n) {
        cin >> A[i];
        for( auto it : adj[A[i]] ) {
            p.pb( it );
        }
        if( A[i] == 1 ) cnt1 ++; 
    }
    for( auto it: p ) {
        if( !M[it] ) M[it] = ++ cnt;
    }
 
    dsu tree(cnt);
    fr(i, 1, n) {
        fr(j, 1, int(adj[A[i]].size()) - 1) {
            cnt -= tree.add_edge(M[adj[A[i]][j-1]], M[adj[A[i]][j]]);
        }
    }
    cnt += cnt1;
    cnt = power(2, cnt) - 2;
    if( cnt < 0 ) cnt += mod; 
    cout << cnt << "\n";
    for( auto it: p ) {
        M[it] = 0;
    }
}

int main() {
    int t; cin >> t;
    sieve();
    for(int i=1; i<=t; i++) solve( i );
    return 0;
}