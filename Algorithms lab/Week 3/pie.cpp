#include <iostream>
#include <cmath>
#include <algorithm>
#include<iomanip>

using namespace std;

double v[10005]; //volumes
const double pi = acos(-1);
int r[10005]; //radii
int check(int N, int F, double c) {
    static int i, cut;
    for(i = 0, cut = 0; i < N; i++) {
        cut += (int)(v[i]/c);
        if(cut >= F)    return 1;
    }
    return 0;
}

int main() {
    int testcase;
    int N, F;
    int i, j, k;
    cin >> testcase;
    while(testcase--) {
        cin >> N >> F;
        F++;
        for(i = 0; i < N; i++)
            cin >> r[i];
        double sum = 0;
        for(i = 0; i < N; i++) {
            v[i] = r[i]*r[i]*pi;
            sum += v[i];
        }
        double l = 0, r = sum/F, m;
#define eps 1e-4
        int flag, cnt = 0;
        while(fabs(l-r) > eps) {
            m = (l+r)/2;
            flag = check(N, F, m);
            if(flag == 0)   r = m;
            else            l = m;
        }
        cout << fixed;
        cout << setprecision(4);
        cout << m;
        cout << endl;
    }
    return 0;
}
