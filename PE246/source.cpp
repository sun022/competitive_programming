#include <bits/stdc++.h>

using namespace std;

constexpr long double A = 7500;
constexpr long double C = 5000;
constexpr long double B = sqrt(A*A - C*C);

// eclipse: 
// (x/a)^2 + (y/b)^2 = 1

long double PI = acos(-1.0L);

bool get_det(const long double x0, const long double y0, const long double t){
    const long double a = (long double)cos(t)*cos(t)/A/A + (long double)sin(t)*sin(t)/B/B;
    const long double b = (long double)2*x0*cos(t)/A/A + (long double)2*y0*sin(t)/B/B;
    const long double c = (long double)x0*x0/A/A + (long double)y0*y0/B/B - 1;
        
    return b*b - 4*a*c >= 0;
}

bool find_angle(int64_t x0, int64_t y0){

    int num_hit = 0;
    int hit_index = -1;
    for(int i = 0; i < 4; i++){
        long double t = (PI/4)*i;
        
        if(get_det(x0, y0, t)){
            // cout << t << endl;
            num_hit++;
            hit_index = i;
        }
    }

    if(num_hit == 0)
        return false;
    if(num_hit >= 2)
        return true;

    long double p1 = (PI/4)*(hit_index-1); // det < 0
    long double q1 = (PI/4)*(hit_index); // det >= 0
    long double p2 = (PI/4)*(hit_index); // det >= 0
    long double q2 = (PI/4)*(hit_index+1); // det < 0

    // cout << p1 << " " << q1 << " " << q2 << endl;

    while(q1-p1 >= 1e-15){
        long double m = (p1+q1)/2;
        if(get_det(x0, y0, m))
            q1 = m;
        else
            p1 = m;
    }

    while(q2-p2 >= 1e-15){
        long double m = (p2+q2)/2;
        if(get_det(x0, y0, m))
            p2 = m;
        else
            q2 = m;
    }

    // cout << p1 << " " << p2 << endl;
    if(p2 - p1 > PI/4 + 1e-16) return true; // equality should be return false
    return false;
}

bool inside_elipse(int64_t x0, int64_t y0){ // on elipse should be return true
    return x0*x0*31250000 + y0*y0*7500*7500 <= (int64_t)7500*7500*31250000;
}

int main(){

    int64_t count = 0;
    for(int64_t x0 = -16000; x0 <= 16000; x0++){
        if(!find_angle(x0, 0)) continue;

        int64_t y0_p = 0;       // true
        int64_t y0_q = 20000;   // false

        // look for LAST true
        while(y0_p != y0_q) {
            // cout << y0_p << " " << y0_q << endl;
            int64_t m = (y0_p+y0_q+1)/2;
            if(find_angle(x0, m))
                y0_p = m;
            else
                y0_q = m - 1;
        }

        // int64_t y0 = 0;
        // while(find_angle(x0, y0+1)) y0++;
        // if(y0 != y0_p) { exit(0); }

        // cout << x0 << "\t" << y0_p << endl;
        count += 1 + y0_p*2;
    }

    cout << "COUNT:" << count << endl;

    return 0;
}