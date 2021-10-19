#include <iostream>
#include <vector>
#include <cmath>
#include <ostream>
#include <list>
#include <map>
#include <algorithm>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <deque>
#include <set>
#include <stack>
#include <queue>
#include <chrono>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define modd 998244353
#define ll long long
#define ld long double
#define mod 1000000007
#define cbit __builtin_popcountll
#define pl pair<long, long>
// #define double long double
#define pqp priority_queue<pl>
#define mkp make_pair
#define vl vector<ll>
#define vvl vector<vl >
#define pb push_back
#define inf 1000000000000000000
#define all(v) v.begin(), v.end()
ll N=0;
ll ans=0;
ll getMin(vector<ld> arr)
{
    ll minInd = 0;
    for (ll i=1; i<N; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}
ll getMax(vector<ld> arr)
{
    ll maxInd = 0;
    for (ll i=1; i<N; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}

ll minOf2(ll x, ll y)
{
    return (x<y)? x: y;
}
ld eps=1e-4;
void minCashFlowRec(vector<ld> amount)
{
    ll mxCredit = getMax(amount), mxDebit = getMin(amount);
    // cout<<amount[mxCredit]<<" "<<amount[mxDebit]<<"\n"; 
    if (abs(0-amount[mxCredit]) <= eps || abs(0-amount[mxDebit]) <= eps)
    {
        
        return;
    }
    ld min = minOf2(-amount[mxDebit], amount[mxCredit]);
    if(abs(min)<=eps)
    {
        return;
    }
    amount[mxCredit] -= min;
    amount[mxDebit] += min;

    ans++;
    // for(auto itr:amount)
    // {
    //     cout<<itr<<" ";
    // }
    // cout<<"\n";
    minCashFlowRec(amount);
}

void minCashFlow(vector<vector<ld> > & graph)
{
    vector<ld> amount(N,0);

    for (ll p=0; p<N; p++)
       for (ll i=0; i<N; i++)
          amount[p] += (graph[i][p] -  graph[p][i]);
 
    minCashFlowRec(amount);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin>>N;
    vector<vector<ld> > graph(N,vector<ld> (N,0));
    for(ll i=0;i<N;i++)
    {
        ll a,b;
        ld c;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        if(s=="Dollar")
        {
            graph[a-1][b-1]+=c;
        }
        else if(s=="Euro")
        {
            c=c*1.8;
            graph[a-1][b-1]+=c;
        }
        else if(s=="Rupees")
        {
            c=c*0.013;
            graph[a-1][b-1]+=c;
        }
    }
    minCashFlow(graph);
    cout<<ans;
    return 0;
}
