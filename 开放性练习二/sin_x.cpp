#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define ld long double
const ld pi = 3.1415926535;
const ld eps = 0.5e-13;

int main() {
    ld angle;
    cin >> angle;
    // Scheme-1
//    while (angle > pi || angle < -pi) {
//        if (angle > pi) {
//            angle -= 2 * pi;
//        }
//        else {
//            angle += 2 * pi;
//        }
//    }
	
    // // Scheme-2
    // while (angle > 2 * pi || angle < 0) {
    //     if (angle > 2 * pi) {
    //         angle -= 2 * pi;
    //     }
    //     else {
    //         angle += 2 * pi;
    //     }
    // }
    ld div = 1.0, res = 0.0, flag = 1.0, cur = angle;
    while (true) {
        if (fabs(cur) < eps) {
            break;
        }
        res += flag * cur;
        flag = -flag;
        cur = cur / (div + 1) * angle / (div + 2) * angle;
        div += 2.0;
    }
    cout << fixed << setprecision(13) << res << endl;
    /**
     *  -0.8026659533203
     *  -0.8026659532131
     */
    return 0;
}
