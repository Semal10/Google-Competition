#include<bits/stdc++.h>
#include<climits>

using namespace std;

#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
#define fie(i,a,b) for(i=a;i<b;i++)
#define MOD 1000000007
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define ll long long
#define lld long long int
#define ALL(x) (x).begin(),(x).end()

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pair<int, int>> vpi;
typedef long long LL;

const lld INF = (1ll) << 56;
const long long OO = 2e18;
const double pi = 2 * acos(0.0);

lld q, t, b, i, j, si , di;
vector<lld> a, same, upd;

void out(lld i) {
	cout << i << endl;
	cout.flush();
}

void out(string i) {
	cout << i << endl;
	cout.flush();
}

lld ask(lld ind) {
	int x;
	out(ind + 1),q++;
	cin >> x;
	return x;
}

void init() {
	q = 0;
	a = same = {};
	a.resize(b, -1);
	same.resize(b, 0);
	si = di = -1;
	upd = {0, 0};
}

int main() {
	fast;
    cin.tie(0);
	cin >> t >> b;

	while (t-- > 0) {
		init();
		for (i = 0; i <b / 2; i++) {
			if (q % 10 == 0 && si != di) {
				if (si == -1 || di == -1) {
					lld x = max(si, di);
					upd[1] = upd[0] = ask(x)^a[x];
					ask(0);
				}
				else {
					upd[1] = ask(si)^a[si];
					upd[0] = ask(di)^a[di];
				}
				for (lld k = 0; k < b; k++) {
					a[k] ^= upd[same[k]];
				}
			}
			j = b - i - 1;
			a[i] = ask(i);
			a[j] = ask(j);
			if (a[i] == a[j]) {
				si = i;
				same[i] = same[j] = 1;
			}
			else di = i;
		}
		string ans = "";
		for (lld x : a) ans += x + '0';
		out(ans);

		char v;
		cin >> v;
		assert(v == 'Y');
	}

}
