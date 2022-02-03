/*You have n students under your control and you have to compose exactly two teams consisting of some subset of your students. Each student had his own skill, the i-th student skill is denoted by an integer ai (different students can have the same skills).

So, about the teams. Firstly, these two teams should have the same size. Two more constraints:

The first team should consist of students with distinct skills (i.e. all skills in the first team are unique).
The second team should consist of students with the same skills (i.e. all skills in the second team are equal).
Note that it is permissible that some student of the first team has the same skill as a student of the second team.

Consider some examples (skills are given):

[1,2,3], [4,4] is not a good pair of teams because sizes should be the same;
[1,1,2], [3,3,3] is not a good pair of teams because the first team should not contain students with the same skills;
[1,2,3], [3,4,4] is not a good pair of teams because the second team should contain students with the same skills;
[1,2,3], [3,3,3] is a good pair of teams;
[5], [6] is a good pair of teams.
Your task is to find the maximum possible size x for which it is possible to compose a valid pair of teams, where each team size is x (skills in the first team needed to be unique, skills in the second team should be the same between them). A student cannot be part of more than one team.

You have to answer t independent test cases.*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
#define MOD 1000000007
#define int long long int
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define print(a)          \
	for (auto x : a)      \
		cout << x << " "; \
	cout << endl
#define print1(a)    \
	for (auto x : a) \
	cout << x.F << " " << x.S << endl
#define print2(a, x, y)         \
	for (int i = x; i < y; i++) \
		cout << a[i] << " ";    \
	cout << endl
 
inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1)
			x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}
inline int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
	const char *comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
 
const int N = 200005;
int bs(int a[], int n, int j)
{
	int i = 0, k = n;
	while (i < k)
	{
		int mid = (i + k) / 2;
		if (a[mid] > j)
			k = mid - 1;
		else if (j < a[mid])
			i = mid + 1;
		else
			return mid;
	}
}
 
void solve()
{
	int t,n,a;
	cin>>n; int ar[n];
 
		int mx=0,x=0;
 
		for(int i=1;i<=n;i++)ar[i]=0;
 
		for(int i=1;i<=n;i++)
            {
			cin>>a;
			ar[a]++;
			if(ar[a]==1)x++;
		  mx=max(mx,ar[a]);
		}
		cout<<max(min(x-1,mx),min(x,mx-1))<<endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	clock_t z = clock();
 
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
 
	return 0;
}