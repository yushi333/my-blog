#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b) { 
    if(b==0)return a ;
    return gcd(b, a % b);}
int lcm(int a, int b) {
     return a / gcd(a, b) * b; }
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, m;
        cin >> a >> b >> c >> m;
        int A = m / a;
        int B = m / b;
        int C = m / c;
        int lcm_ab = lcm(a, b);
        int lcm_ac = lcm(a, c);
        int lcm_bc = lcm(b, c);
        int lcm_abc = lcm(lcm_ab, c);
        int AB = m / lcm_ab;
        int AC = m / lcm_ac;
        int BC = m / lcm_bc;
        int ABC = m / lcm_abc;
        int A_single = A - (AB + AC - ABC);
        int B_single = B - (AB + BC - ABC);
        int C_single = C - (AC + BC - ABC);
        int AB_only = AB - ABC;
        int AC_only = AC - ABC;
        int BC_only = BC - ABC;
        int wA = A_single * 6 + (AB_only + AC_only) * 3 + ABC * 2;
        int wB = B_single * 6 + (AB_only + BC_only) * 3 + ABC * 2;
        int wC = C_single * 6 + (AC_only + BC_only) * 3 + ABC * 2;
        cout << wA << " " << wB << " " << wC <<endl;
    }
    return 0;
}
//据我的分析，应该是要找出，每个人的三人冲突天数，两人冲突天数和单人取水天数，最后带权乘起来相加，
//所以要找a,b,c任意两者的最小公倍数，若a,b间隔为2，3则每6重合一次，再找6和1的最小公倍数，6所以6为三人重合间隔
//先找两个人，找出三个后再看这个三个间隔会不会相串；
//m/a求出总打水天数，然后要减去共同大水，共5天，4天2人打，1天三人打，4*3+2=14
//验证成功，嘿嘿，我看看接下来怎么搞
//1->10->5+3+2->1天三人，5天2人，三天2人，2天单人；8*3+2*6+2=38
//