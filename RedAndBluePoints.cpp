#include <bits/stdc++.h>
using namespace std;

#define eps (1e-9)
#define zero(a) (fabs(a)<eps)
#define x first
#define y second
#define pb push_back
#define mp make_pair
const double pi=acos(-1.0);
typedef int type;
typedef pair<int,int> point;

inline point sub(point a,point b)
{
	return make_pair(a.x-b.x,a.y-b.y);
}
inline type cross(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}
inline type sqdis(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
type cross(point o,point a,point b) // oa x ob
{
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
void hull(vector<point> &P,vector<point> &R)
{
	int n=P.size(),k=0;
	vector<int> H(2*n);
	sort(P.begin(),P.end());
	for(int i=0;i<n;i++)
	{
		while(k>=2 && cross(P[H[k-2]],P[i],P[H[k-1]])>=0)k--;
		H[k++]=i;
	}
	for(int i=n-2,t=k+1;i>=0;i--)
	{
		while(k>=t && cross(P[H[k-2]],P[i],P[H[k-1]])>=0)k--;
		H[k++]=i;
	}
	H.resize(k-1);
	for(int i=0;i<k-1;i++)R.push_back(P[H[i]]);
}
inline bool eqn(point p,point q,double &a,double &b,double &c) // ax+by=c
{
	if(zero(p.x-q.x) && zero(p.y-q.y))return false;
	a=p.y-q.y;
	b=q.x-p.x;
	c=p.y*q.x-p.x*q.y;
	return true;
}
inline std::ostream & operator <<(std::ostream &o,point a){o<<"("<<a.x<<","<<a.y<<")";return o;}
inline std::istream & operator >>(std::istream &i,point &a){i>>a.x>>a.y;return i;}
inline bool onsegment(point pi,point pj,point pk)
// given pk is on the line made by the segment pipj, is pk on the segment pipj?
{
	return min(pi.x,pj.x)<=pk.x && pk.x<=max(pi.x,pj.x) && min(pi.y,pj.y)<=pk.y && pk.y<=max(pi.y,pj.y);
}
inline bool isintersect(point p1,point p2,point p3,point p4)	// is p1p2 and p3p4 intersects?
{
	type d1=cross(sub(p1,p3),sub(p4,p3));
	type d2=cross(sub(p2,p3),sub(p4,p3));
	type d3=cross(sub(p3,p1),sub(p2,p1));
	type d4=cross(sub(p4,p1),sub(p2,p1));
	if(((d1>0&&d2<0) || (d1<0&&d2>0)) && ((d3>0&&d4<0) || (d3<0&&d4>0)))return true;
	if(zero(d1) && onsegment(p3,p4,p1))return true;
	if(zero(d2) && onsegment(p3,p4,p2))return true;
	if(zero(d3) && onsegment(p1,p2,p3))return true;
	if(zero(d4) && onsegment(p1,p2,p4))return true;
	return false;
}
inline bool eqnsolve(double a1,double b1,double c1,double a2,double b2,double c2,pair<double,double> &ans)
{
	// a1x+b1x=c1 and a2x+b2y=c2
	if(zero(a2*b1-a1*b2))return false;
	ans.x=(c1*b2-c2*b1)/(a1*b2-a2*b1);
	ans.y=(c1*a2-c2*a1)/(a2*b1-a1*b2);
	return true;
}

vector<point> circle_line(double r,double a,double b,double c) 
// intersecting point(s) between x*x+y*y=r*r and ax+by+c=0
{
	vector<point> ret;
	double x0=-a*c/(a*a+b*b);
	double y0=-b*c/(a*a+b*b);
	if(c*c>r*r*(a*a+b*b)+eps)return ret;
	else if(zero(c*c - r*r*(a*a+b*b)))ret.pb(mp(x0,y0));
	else
	{
		double d=r*r-c*c/(a*a+b*b);
		double mult=sqrt(d/(a*a+b*b));
		double ax,ay,bx,by;
		ax=x0+b*mult;
		bx=x0-b*mult;
		ay=y0-a*mult;
		by=y0+a*mult;
		ret.pb(mp(ax,ay));
		ret.pb(mp(bx,by));
	}
	return ret;
}

vector<point> circle_circle(double r1,double r2,double x2,double y2)
// intersection point(s) between two <different> circles x*x+y*y=r1*r1 and (x-x2)*(x-x2)+(y-y2)*(y-y2)=r2*r2
{
	double a=-2*x2,b=-2*y2,c=(x2*x2+y2*y2+r1*r1-r2*r2);
	return circle_line(r1,a,b,c);
}

/* **************************** not so important **************************** */
inline point add(point a,point b)
{
	return make_pair(a.x+b.x,a.y+b.y);
}
inline type sqval(point a)
{
	return a.x*a.x+a.y*a.y;
}
inline double val(point a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}
inline type dot(point a,point b)
{
	return a.x*b.x+a.y*b.y;
}
inline double angle(point a,point b)	// angle aob
{
	return acos(1.0*(a.x*b.x+a.y*b.y)/(sqrt(a.x*a.x+a.y*a.y)*sqrt(b.x*b.x+b.y*b.y)));
}
inline double angle(point a,point b,point c)	// angle abc
{
	a=make_pair(a.x-b.x,a.y-b.y);
	b=make_pair(c.x-b.x,c.y-b.y);
	return acos(1.0*(a.x*b.x+a.y*b.y)/(sqrt(a.x*a.x+a.y*a.y)*sqrt(b.x*b.x+b.y*b.y)));
}
/* **************************** not so important **************************** */

class RedAndBluePoints {
    bool is_inside(vector <point> &H, point p) {
        int n = H.size();
        for (int i = 0; i < n; i ++) {
            if (cross(H[i], H[(i+1)%n], p) < 0) {
                return false;
            }
        }
        return true;
    }
    bool is_left(vector <point> &red, point a, point b) {
        for (auto r: red) {
            if (cross(a, b, r) <= 0) {
                return false;
            }
        }
        return true;
    }
    int count_right(vector <point> &blue, point a, point b) {
        int ret = 0;
        for (auto l: blue) {
            if (cross(a, b, l) <= 0) {
                ret ++;
            }
        }
        return ret;
    }
public:
	int find(vector <int> blueX, vector <int> blueY, vector <int> redX, vector <int> redY) {
		int ret = 1;
        vector <point> P, H;
        vector <point> red, blue;
        for (int i = 0; i < (int)blueX.size(); i ++) {
            P.push_back(make_pair(blueX[i], blueY[i]));
            blue.push_back(make_pair(blueX[i], blueY[i]));
        }
        hull(P, H);
        for (int i = 0; i < int(redX.size()); i ++) {
            if (is_inside(H, make_pair(redX[i], redY[i]))) {
                red.push_back(make_pair(redX[i], redY[i]));
            }
        }
        for (int i = 0, j = 1; i < int(H.size()); i ++) {
            while (j != i && is_left(red, H[i], H[j])) {
                j = (j+1) % int(H.size());
            }
            int k = (j-1+int(H.size())) % int(H.size());
            if (i == k) {
                continue;
            }
            ret = max(ret, count_right(blue, H[i], H[k]));
        }
		return ret;
	}
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int blueX[]               = {0,0,10,10};
			int blueY[]               = {0,10,0,10};
			int redX[]                = {100};
			int redY[]                = {120};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = RedAndBluePoints().find(vector <int>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <int>(blueY, blueY + (sizeof blueY / sizeof blueY[0])), vector <int>(redX, redX + (sizeof redX / sizeof redX[0])), vector <int>(redY, redY + (sizeof redY / sizeof redY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int blueX[]               = {0,0,10,10};
			int blueY[]               = {0,10,0,10};
			int redX[]                = {3};
			int redY[]                = {4};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = RedAndBluePoints().find(vector <int>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <int>(blueY, blueY + (sizeof blueY / sizeof blueY[0])), vector <int>(redX, redX + (sizeof redX / sizeof redX[0])), vector <int>(redY, redY + (sizeof redY / sizeof redY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int blueX[]               = {0,0,10,10};
			int blueY[]               = {0,10,0,10};
			int redX[]                = {3,6};
			int redY[]                = {2,7};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = RedAndBluePoints().find(vector <int>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <int>(blueY, blueY + (sizeof blueY / sizeof blueY[0])), vector <int>(redX, redX + (sizeof redX / sizeof redX[0])), vector <int>(redY, redY + (sizeof redY / sizeof redY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int blueX[]               = {0};
			int blueY[]               = {0};
			int redX[]                = {1};
			int redY[]                = {1};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = RedAndBluePoints().find(vector <int>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <int>(blueY, blueY + (sizeof blueY / sizeof blueY[0])), vector <int>(redX, redX + (sizeof redX / sizeof redX[0])), vector <int>(redY, redY + (sizeof redY / sizeof redY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int blueX[]               = {5, 6, 6};
			int blueY[]               = {9, 0, 5};
			int redX[]                = {7};
			int redY[]                = {6};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = RedAndBluePoints().find(vector <int>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <int>(blueY, blueY + (sizeof blueY / sizeof blueY[0])), vector <int>(redX, redX + (sizeof redX / sizeof redX[0])), vector <int>(redY, redY + (sizeof redY / sizeof redY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int blueX[]               = ;
			int blueY[]               = ;
			int redX[]                = ;
			int redY[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RedAndBluePoints().find(vector <int>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <int>(blueY, blueY + (sizeof blueY / sizeof blueY[0])), vector <int>(redX, redX + (sizeof redX / sizeof redX[0])), vector <int>(redY, redY + (sizeof redY / sizeof redY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int blueX[]               = ;
			int blueY[]               = ;
			int redX[]                = ;
			int redY[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RedAndBluePoints().find(vector <int>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <int>(blueY, blueY + (sizeof blueY / sizeof blueY[0])), vector <int>(redX, redX + (sizeof redX / sizeof redX[0])), vector <int>(redY, redY + (sizeof redY / sizeof redY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int blueX[]               = ;
			int blueY[]               = ;
			int redX[]                = ;
			int redY[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RedAndBluePoints().find(vector <int>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <int>(blueY, blueY + (sizeof blueY / sizeof blueY[0])), vector <int>(redX, redX + (sizeof redX / sizeof redX[0])), vector <int>(redY, redY + (sizeof redY / sizeof redY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
