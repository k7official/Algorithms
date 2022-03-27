#include <bits/stdc++.h>
using namespace std;

const int MXN = 10000;
const int INF = (int)1e9;
class Point
{
public:
    double x, y;

};
Point P[MXN];
int N;

/*int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}*/
bool compareX(const Point& l, const Point& r)
{
    return l.x < r.x;
}

bool compareY(const Point& l, const Point& r)
{
    return l.y < r.y;
}
float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y)
            );
}
float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
float min(float x, float y)
{
    return (x < y)? x : y;
}
float stripClosest(Point strip[], int size, float d)
{
    float min = d; // Initialize the minimum distance as d
 
    //qsort(strip, size, sizeof(Point), compareY);
    sort(P, P + N, compareY);
 
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
 
    return min;
}
// A recursive function to find the
// smallest distance. The array P contains
// all points sorted according to x coordinate
float closestUtil(Point P[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);
 
    // Find the middle point
    int mid = n/2;
    Point midPoint = P[mid];
 
    // Consider the vertical line passing
    // through the middle point calculate
    // the smallest distance dl on left
    // of middle point and dr on right side
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);
 
    // Find the smaller of two distances
    float d = min(dl, dr);
 
    // Build an array strip[] that contains
    // points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
 
    // Find the closest points in strip.
    // Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}
// The main function that finds the smallest distance
// This method mainly uses closestUtil()
float closest(Point P[], int n)
{
   // qsort(P, n, sizeof(Point), compareX);
    sort(P, P + N, compareX);
 
    // Use recursive function closestUtil()
    // to find the smallest distance
    return closestUtil(P, n);
}
 
void read()
{
    for(int i=0; i<N; i++)
    {
        cin >> P[i].x >> P[i].y;
    }
}
void solve()
{
    double smallest_dist = closest(P, N);
    if(smallest_dist>=1e4)
        cout << "INFINITY" << endl;
    else cout << setprecision(4) << fixed << smallest_dist << endl;
}
// Driver code
int main()
{
    
    while(cin >> N && N)
    {
        read();
        solve();
    }
    return 0;
}
