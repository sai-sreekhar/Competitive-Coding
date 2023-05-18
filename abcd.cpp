/*
    Author: Sai Sreekar
    Created:
    Last Modified:
*/

#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;

// Debug Utils
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

template <typename... Params>
void _print(priority_queue<Params...> q)
{
    while (!q.empty())
    {
        cerr << " " << q.top() << ",";
        q.pop();
    }
    cerr << "]" << endl;
}

// Operator Overloads
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second << "\n"); }
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <algorithm>
using namespace std;

struct point
{
    int x;
    int y;
} p0;
point nextToTop(stack<point> &stack)
{
    point top = stack.top();
    stack.pop();
    point nttop = stack.top();
    stack.push(top);
    return nttop;
}

void swap(point &p1, point &p2)
{
    point temp = p1;
    p1 = p2;
    p2 = temp;
}

int distSq(point p1, point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

int ccw(point a, point b, point c)
{
    int area = (b.y - a.y) * (c.x - b.x) -
               (b.x - a.x) * (c.y - b.y);

    if (area == 0)
        return 0;
    return (area > 0) ? 1 : 2;
}

int comparator(const void *vp1, const void *vp2)
{
    point *p1 = (point *)vp1;
    point *p2 = (point *)vp2;
    int o = ccw(p0, *p1, *p2);
    if (o == 0)
    {
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1; // if collinear, we sort if p2 is smaller than p1s
    }
    return (o == 2) ? -1 : 1; // Sort if its c-clockwise
}

bool compare(point &p1, point &p2)
{
    int o = ccw(p0, p1, p2);
    if (o == 0)
    {
        return (distSq(p0, p2) >= distSq(p0, p1)); // if collinear, we sort if p2 is smaller than p1s
    }
    return (o == 2); // Sort if its c-clockwise
}

void convex_hull(vector<point> &points)
{

    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        cout << points[i].x << " " << points[i].y << "\n";
    }
    int ymin = points[0].y;
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        {
            ymin = y;
            min = i;
        }
    }

    swap(points[0], points[min]);
    p0 = points[0];
    sort(next(points.begin()), points.end(), compare);

    // qsort(&points[1], n - 1, sizeof(point), comparator);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << points[i].x << " " << points[i].y << "\n";
    // }
    // sort(points.begin(), points.end(), comparator);
    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && ccw(p0, points[i], points[i + 1]) == 0)
            i++;
        points[m] = points[i];
        m++;
    }
    stack<point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    for (int i = 3; i < m; i++)
    {

        while (S.size() > 1 && ccw(nextToTop(S), S.top(), points[i]) != 2)
        {
            S.pop();
        }
        S.push(points[i]);
    }

    while (!S.empty())
    {
        point p = S.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }
}
int main()
{

    vector<point> points(18);

    points[0].x = -7;
    points[0].y = 8;

    points[1].x = -4;
    points[1].y = 6;

    points[2].x = 2;
    points[2].y = 6;

    points[3].x = 6;
    points[3].y = 4;

    points[4].x = 8;
    points[4].y = 6;

    points[5].x = 7;
    points[5].y = -2;

    points[6].x = 4;
    points[6].y = -6;

    points[7].x = 8;
    points[7].y = -7;

    points[8].x = 0;
    points[8].y = 0;

    points[9].x = 3;
    points[9].y = -2;

    points[10].x = 6;
    points[10].y = -10;

    points[11].x = 0;
    points[11].y = -6;

    points[12].x = -9;
    points[12].y = -5;

    points[13].x = -8;
    points[13].y = -2;

    points[14].x = -8;
    points[14].y = 0;

    points[15].x = -10;
    points[15].y = 3;

    points[16].x = -2;
    points[16].y = 2;

    points[17].x = -10;
    points[17].y = 4;

    convex_hull(points);
    return 0;
}