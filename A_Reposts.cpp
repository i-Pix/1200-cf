
#include<bits/stdc++.h> // NOTE : TURN OFF WHEN NOT USED IN COMPETITIVE PROGRAMMING.

using namespace std;
using namespace chrono;
///* POLICY BASED DATA STRUCTURE */
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T>
//#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

//-------------------------------------------------------Typedefs----------------------------------------------//
typedef  long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef unordered_set<ll> uo_s;
typedef unordered_map<ll, ll> uo_m;
typedef map<ll, ll> o_m;
double EPS = 1e-9;
int INF5 = 1000000005;
int INF7 = 1000000007;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
void read(ll &sum) {sum = 0; char c = getchar( ); bool f = 0; while (c < '0' || c > '9')
    {if (c == '-') f = 1; c = getchar( );} while (c >= '0' && c <= '9')
    {sum = sum * 10 + c - '0'; c = getchar( );} if (f) sum = -sum;}

//---------------------------------------------------------Hash defines--------------------------------------------------//
/* TESTING */
# define    PII     3.14159265358979323846
ll power(ll x, ll y){
    ll res = 1;
    while(y){
        if(y&1) res = (res*x)%998244353;
        y >>= 1;
        x = (x*x)%998244353;
    }
    return res;
}
/* HASH DEFINES */
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define FOREACHIT(it,a,b) for(auto it = a; it != b; it++)
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((ll)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define T(a) ll a; cin >> a;
#define TT(a,b) ll a,b; cin >> a >> b;
#define TEST(t) T(t); while (t--)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define array(a)   ll a[n];
#define line "\n";
#define out(a) cout << a << endl;
#define MaxN    200050
#define transforml(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define transformu(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define array_input(a,n) ll a[n]; REP(i,n) cin >> a[i];
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define Yes cout<<"Yes"<<endl;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define No cout<<"No"<<endl;
#define instant_array T(n)arrayinp(a,n)
#define show(arr) { for (auto x: arr) cout << x << " "; cout << '\n'; }
//-------------------------------------------------TEMPLATES----------------------------------------------------------//
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
////////////////////////////////////////////////////////////////////////////////
static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randNo(int lower_limit, int upper_limit){

    return lower_limit + rng()%(upper_limit-lower_limit);
}
int solve2(int arr[], int n) {
    int ans = 0 ;

    //write here your brute force solution

    return ans;
}
bool isPrime(long long int n){ for (ll i = 2; i*i <= n; i++) if (n % i == 0) return false;    return true;}
//////////////////////////////////////////////////////////////////////////////
#define fib(n) round(pow(((1+sqrt(5))/2),n)/sqrt(5))  //fibonacci in O(1)

void theGiftGambit() {
    int n;
   
    cin >> n; map<string,int> mp;
    int ans = 0;
    while(n--){
        string a,_,c;
        cin >> a >> _ >> c;
        transforml(a);
        transforml(c);
        mp[a]=mp[c]+1;
        ans = max(ans,mp[a]);
    }
    cout << ans + 1;
}
signed main() {
    IOS
//    ll t;
//    cin>>t;
//    for(int j=1;j<=t; j++)
//    {
//        cout<<"Case #"<<j<<": ";

//T(t)
//REPN(i,t) {
//    cout<<"Case #"<<i<<": ";
//        TEST(q)
    theGiftGambit();

//}
    //    }
    return 0;
}



