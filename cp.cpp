/*After you had helped George and Alex to move in the dorm, they went to help their friend Fedor play a new computer game «Call of Soldiers 3».

The game has (m + 1) players and n types of soldiers in total. Players «Call of Soldiers 3» are numbered form 1 to (m + 1). Types of soldiers are numbered from 0 to n - 1. Each player has an army. Army of the i-th player can be described by non-negative integer xi. Consider binary representation of xi: if the j-th bit of number xi equal to one, then the army of the i-th player has soldiers of the j-th type.

Fedor is the (m + 1)-th player of the game. He assume that two players can become friends if their armies differ in at most k types of soldiers (in other words, binary representations of the corresponding numbers differ in at most k bits). Help Fedor and count how many players can become his friends.*/
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
 int solve(int A, int B)
{
    int XOR = A ^ B;
    // Check for 1's in the binary form using
    // Brian Kerninghan's Algorithm
    int count = 0;
    while (XOR) {
        XOR = XOR & (XOR - 1);
        count++;
    }
    return count;
}
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	int a[m+1];
	for(int i=0;i<m+1;i++)
	cin>>a[i];
	int i=0,c=0;
	while(i<m)
	{
		int d = solve(a[i],a[m]);
		if(d<=k)
		{
		c++;
		}
		i++;
	}
	cout<<c<<endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	clock_t z = clock();
 
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
 
	return 0;
}