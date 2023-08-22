#include<bits/stdc++.h>
using namespace std;
class black_scholes
{
    private:
    double norm_pdf(const double& x)
    {
        double pdf = (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x);
        return pdf;
    }

    double norm_cdf(const double& x)
    {
        double k = 1.0/(1.0 + 0.2316419*x);
        double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

        if (x >= 0.0) {
            return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    }   else {
            return 1.0 - norm_cdf(-x);
    }
    }
    double d_j(const int& j, const double& S, const double& K, const double& r, const double& v, const double& T) {
    return (log(S/K) + (r + (pow(-1,j-1))*0.5*v*v)*T)/(v*(pow(T,0.5)));
    }
    public:
    double call_price(const double& S, const double& K, const double& r, const double& v, const double& T) {
    return S * norm_cdf(d_j(1, S, K, r, v, T))-K*exp(-r*T) * norm_cdf(d_j(2, S, K, r, v, T));
    }
  
    double put_price(const double& S, const double& K, const double& r, const double& v, const double& T) {
    return -S*norm_cdf(-d_j(1, S, K, r, v, T))+K*exp(-r*T) * norm_cdf(-d_j(2, S, K, r, v, T));
    }

};
int main(int argc, char **argv)
{
    double S,K,R,v,T;
    cout<<"Enter Option Price:";
    cin>>S;
    cout<<"Enter Strike Price:";
    cin>>K;
    cout<<"Enter Risk free rate:";
    cin>>R;
    cout<<"Enter Volatility:";
    cin>>v;
    cout<<"Enter Time";
    cin>>T;
    black_scholes b;
    double call = b.call_price(S,K,R,v,T);
    double put = b.put_price(S,K,R,v,T);
    cout << "Underlying: " << S << std::endl;
    cout << "Strike: " << K << std::endl;
    cout << "Risk-Free Rate: " << r << std::endl;
    cout << "Volatility: " << v << std::endl;
    cout << "Maturity: " << T << std::endl;
    cout << "Call Price: " << call << std::endl;
    cout << "Put Price: " << put << std::endl;
    return 0;
}