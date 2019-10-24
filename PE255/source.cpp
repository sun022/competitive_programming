#include <bits/stdc++.h>

using namespace std;

int64_t f(int64_t n,int64_t x){
    return (x + (n+x-1)/x)/2;
}

vector<int64_t> c(100, 0);
void A(int64_t x, int64_t n1, int64_t n2, int iter){
    int64_t x1_min = f(n1, x);
    int64_t x1_max = f(n2, x);

    for(int64_t x1 = x1_min; x1 <= x1_max; x1++){
        int64_t a = 1 + x*(2*x1 - x -1);
        int64_t b = x*(2*x1 - x + 1);
        a = max(a, n1);
        b = min(b, n2);
        if(x1 == x){
            // cout << x1 << ":\t" << a << "\t" << b << "\t" << iter << endl;
            c[iter] += b-a+1;
        }
        else
            A(x1, a, b, iter+1);
    }
}

int main(){
    // A(200, 10000, 99999, 1);
    A(7*1e6, 1e13, 1e14-1, 1);

    int64_t count = 0;
    int64_t sum = 0;
    for(int i=0;i<100;i++){
        if(c[i] != 0){
            cout << i << ":\t" << c[i] << endl;
            sum += c[i]*i;
            count += c[i];
        }
    }
    cout << sum << endl;
    cout << count << endl;
    long double avg = (long double)sum/(1e14 - 1e13);
    cout << setprecision(15) << avg << endl;

    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    for(int n=10000;n<=99999;n++){
        int x = 200;
        int iter = 0;

        cout << n << ":\t";
        while(true){
            int x_next = (x + (n+x-1)/x)/2;
            iter++;

            if(x_next == x) break;

            x = x_next;
            cout << x << "\t";
        }
        cout << endl;
        // cout << n << "\t" << x << "\t" << iter << endl;
    }

    return 0;
}
*/
