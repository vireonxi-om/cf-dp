// Problem: Polygon
// URL: https://codeforces.com/problemset/problem/1572/E
// Rating: 3000
// Tags: binary search, dp, geometry
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)
 
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long double LD;
 
const int N = 210;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const long long INF = (long long)1e18;
const double eps = 1e-15, pi = acos(-1.0);


namespace PointDouble{
inline int dcmp(double x) {
    return (x > eps) - (x < -eps);
}
struct Point {
    double x, y;
    Point (double x = 0 , double y = 0) : x(x) , y(y) {}
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    bool operator < (const Point& R) const {
        if (dcmp(x - R.x) == 0)
            return dcmp(y - R.y) < 0;
        return dcmp(x - R.x) < 0;
    }
    bool operator == (const Point& R) const {
        return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0;
    }
    Point operator + (const Point& R) const {
        return Point(x + R.x, y + R.y);
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x, y - R.y);
    }
    Point operator * (const double& R) const {
        return Point(x * R, y * R);
    }
    Point operator / (const double& R) const {
        return Point(x / R, y / R);
    }
    double operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
    double operator % (const Point& R) const {
        return x * R.x + y * R.y;
    }
    double len() {
        return sqrt(*this % *this);
    }
    double angle() {
        return atan2(y, x);
    }
};
struct Line {
	Point P, V; //P + Vt
    double angle;
    Line () {}
    Line (Point A , Point B) {
        P = A , V = B - A;
        angle = atan2(V.y , V.x);
    }
    bool operator < (const Line& R) const {
        return angle < R.angle;
    }
    Point point(double t) {
        return P + V * t;
    }
};

int Convex2D(Point p[], int stk[], int used[], Point h[], int n) {
	// n, Points p[N] (will be sorted), int stk[N] & used[N]
	// Point h[1, ..., ans + 1] = convex hull with start point repeated at the end.
	int tp = 0;
	sort(p + 1, p + 1 + n); 
	stk[++tp] = 1;
	for (int i = 2; i <= n; ++i) {
		while (tp >= 2 && dcmp((p[stk[tp]] - p[stk[tp - 1]]) ^ (p[i] - p[stk[tp]])) <= 0)
			used[stk[tp--]] = 0;
		used[i] = 1;  
		stk[++tp] = i;
	}
	int tmp = tp;  
	for (int i = n - 1; i > 0; --i){
	    if (used[i]) continue;
	    while (tp > tmp && dcmp((p[stk[tp]] - p[stk[tp - 1]]) ^ (p[i] - p[stk[tp]])) <= 0)
	    	used[stk[tp--]] = 0;
	    used[i] = 1;
	    stk[++tp] = i;
	}
	for (int i = 1; i <= tp; ++i) h[i] = p[stk[i]];
	return tp - 1;
}

bool OnSegment(Point P, Point a1, Point a2) {
    double len = (P - a1).len();
    if (dcmp(len) == 0) return true;
    a1 = a1 - P , a2 = a2 - P;
    return dcmp((a1 ^ a2) / len) == 0 && dcmp(a1 % a2) <= 0;
}

Point GetLineIntersection(Point P, Point v, Point Q, Point w) {
    Point u = P - Q;
    double t1 = (w ^ u) / (v ^ w);
    return P + v * t1;
}
//exclude intersection of endpoint-endpoint or endpoint-line
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = (a2 - a1) ^ (b1 - a1);
    double c2 = (a2 - a1) ^ (b2 - a1);
    if (dcmp(c1) == 0 && dcmp(c2) == 0) {
        if (a2 < a1) swap(a1 , a2);
        if (b2 < b1) swap(b1 , b2);
        return max(a1 , b1) < min(a2 , b2);
    }
    double c3 = (b2 - b1) ^ (a1 - b1);
    double c4 = (b2 - b1) ^ (a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
//include all intersections 
bool SegmentIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = (a2 - a1) ^ (b1 - a1);
    double c2 = (a2 - a1) ^ (b2 - a1);
    if (dcmp(c1) == 0 && dcmp(c2) == 0) {
        if (a2 < a1) swap(a1 , a2);
        if (b2 < b1) swap(b1 , b2);
        return max(a1 , b1) < min(a2 , b2) || max(a1, b1) == min(a2, b2);
    }
    double c3 = (b2 - b1) ^ (a1 - b1);
    double c4 = (b2 - b1) ^ (a2 - b1);
    return dcmp(c1) * dcmp(c2) <= 0 && dcmp(c3) * dcmp(c4) <= 0;
}

inline bool Onleft(Line L , Point P) {
    return dcmp((L.V ^ (P - L.P))) > 0;
}

//typedef vector<Point> Polygon;
double ConvexPolygonArea(Point *p, int n) {
	double area = 0; 
	rep(i, 1, n - 1) {
		area += ((p[i] - p[0]) ^ (p[i + 1] - p[0]));
	}
	return fabs(area / 2);
}
// Point is strictly inside Polygon. Remember, copy the first vertex to a[n].
bool pointInPolygon(Point P , Point *p , int n) {
    for (int i = 0 ; i < n ; ++ i)
        if (OnSegment(P , p[i] , p[i + 1]))
            return 0;
    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        Point a = p[i] , b = p[i + 1];
        if (a.y > b.y) swap(a , b);
        if (dcmp((a - P) ^ (b - P)) < 0 && dcmp(a.y - P.y) < 0 && dcmp(b.y - P.y) >= 0)
            res ^= 1;
    }
    return res;
}
/*
// Not tested. Lattice points inside non-lattice polygon. divide into  For x = [0, n), y = (0, floor(kx + b)].
int count_lattices(Fraction k, Fraction b, long long n) {
    auto fk = k.floor();
    auto fb = b.floor();
    auto cnt = 0LL;
    if (k >= 1 || b >= 1) {
        cnt += (fk * (n - 1) + 2 * fb) * n / 2;
        k -= fk;
        b -= fb;
    }
    auto t = k * n + b;
    auto ft = t.floor();
    if (ft >= 1) {
        cnt += count_lattices(1 / k, (t - t.floor()) / k, t.floor());
    }
    return cnt;
}
*/
//find halfplane intersection. Note: consider the left plane of each line. 
int HalfPlaneIntersection(Line* L , int n , Point* Poly) {
	Point p[100];
    Line q[100];
    sort(L , L + n);
    int top = 0 , bot = 0;
    q[0] = L[0];
    for (int i = 1 ; i < n ; ++ i) {
        while (top < bot && !Onleft(L[i] , p[bot - 1])) -- bot;
        while (top < bot && !Onleft(L[i] , p[top])) ++ top;
        q[++ bot] = L[i];
        if (dcmp(L[i].V ^ q[bot - 1].V) == 0) {
            -- bot;
            if (Onleft(q[bot] , L[i].P))
                q[bot] = L[i];
        }
        if (top < bot)
            p[bot - 1] = GetLineIntersection(q[bot - 1].P, q[bot - 1].V, q[bot].P, q[bot].V);
        //cout << "tb: " << top << " " << bot << "\n";
        //for (int i = top ; i <= bot ; ++ i) cout << p[i].x << " " << p[i].y << "\n";;
    }
    while (top < bot && !Onleft(q[top] , p[bot - 1])) -- bot;
    if (bot - top <= 1) return 0;
    p[bot] = GetLineIntersection(q[bot].P, q[bot].V, q[top].P, q[top].V);
    int m = 0;
    for (int i = top ; i <= bot ; ++ i) Poly[m ++] = p[i];
    return m;
}

}

namespace PointLL{

struct Point {
    LL x, y;
    Point (LL x = 0 , LL y = 0) : x(x) , y(y) {}
    void input() {
        cin >> x >> y; 
    }
    bool operator < (const Point& R) const {
        if (x - R.x == 0)
            return (y - R.y) < 0;
        return (x - R.x) < 0;
    }
    bool operator == (const Point& R) const {
        return (x - R.x) == 0 && (y - R.y) == 0;
    }
    Point operator + (const Point& R) const {
        return Point(x + R.x, y + R.y);
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x, y - R.y);
    }
    Point operator * (const LL& R) const {
        return Point(x * R, y * R);
    }
    /*
    Point operator / (const double& R) const {
        return Point(x / R, y / R);
    }
    */
    LL operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
    LL operator % (const Point& R) const {
        return x * R.x + y * R.y;
    }
    LL slen() {
        return *this % *this;
	}
    /*
    double len() {
        return sqrt(*this % *this);
	}
    double angle() {
        return atan2(y, x);
    } */
};
}



using namespace PointLL;

int n, tot, dp[N][N];
LL tri[N][N][N];
LL lf[N][N];
Point p[N]; 

LL work(int i, int j, int k) {
	return abs((p[j] - p[i]) ^ (p[k] - p[i]));
}
void upd(int i, int j, int cnt, LL cur) {
	if (cnt > dp[i][j]) {
		dp[i][j] = cnt; lf[i][j] = cur; 
	}
	else if (cnt == dp[i][j]) lf[i][j] = max(lf[i][j], cur);
}

int main() {
	cin >> n >> tot;
	tot ++;
	rep(i, 0, n) cin >> p[i].x >> p[i].y;
	LL l = 0, r = 1e18;
	LL ans = 0;
	rep(i, 0, n) {
		rep(j, 0, n) {
			rep(k, 0, n) tri[i][j][k] = work(i, j, k);
		}
	}
	while (l <= r) {
		rep(i, 0, n) {
			rep(j, 0, n) {
				dp[i][j] = 0; lf[i][j] = 0;
			}
		}
		LL s = (l + r) / 2;
		bool can = false;
		//cout << s << "\n";
		repn(t, 2, n - 1) {
			rep(i, 0, n) {
				int j = (i + t) % n;
				LL cur;
				rep(t1, 1, t) {
					int k = (i + t1) % n;
					cur = tri[k][i][j] + lf[i][k] + lf[k][j];
					if (cur >= s) {
						upd(i, j, dp[k][j] + dp[i][k] + 1, 0);
					}
					else upd(i, j, dp[k][j] + dp[i][k], cur);
				}
				//cout << i << " " << j << " " << cur << "\n";
				if (dp[i][j] >= tot) {
					can = true;
					//cout << "tmp " << i << " " << j << " " << dp[i][j] << "\n";
				}
			}
		}
		if (can) {
			ans = max(ans, s); l = s + 1;
		}
		else r = s - 1;
	}
	cout << ans << "\n";
	return 0;
}

