#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]
NumericVector loads(NumericVector feet, double m1, double base_ft, double base_press, double SF) {
    int n = feet.size();
    double calc_0 = 0;
    double calc_1 = 0;
    double calc_2 = 0;
    double calc_3 = 0;
    double calc_4 = 0;
    double calc_5 = 0;
    double calc_6 = 0;
    double calc_7 = 0;
    NumericVector load_psf(n);

    for(int i = 0; i < n; ++i) {
        calc_0 = pow(2 * feet[i] / base_ft, 2.0);
        calc_1 = pow((pow(m1, 2.0) + calc_0) * (calc_0 + 1), 0.5);
        calc_2 = pow(m1, 2.0) + calc_0;
        calc_3 = 1 + calc_0;
        calc_4 = pow(m1, 2.0) + 2 * calc_0 + 1;
        calc_5 = (-2) * m1 * feet[i] / base_ft;
        calc_6 = pow(m1, 2.0) + calc_0 + 1;
        calc_7 = asin(m1 / calc_1);
        load_psf[i] = 2 * base_press * SF *((calc_5 / pow(calc_6, 0.5)) * calc_4 / (calc_3 * calc_2) + calc_7) / 3.14159265;
    }
    return load_psf;   
}