#include <vector>
// 
using std::vector;

#ifndef BOUNDARY_VALUE_CONDITION
#define BOUNDARY_VALUE_CONDITION

// entity semantic is missing:
// - no virtual destructor, so even if you call delete bv, you'll have
// a potential leak ecause data members of inheriting classes won't be
// deleted
// - copy and move constructors / assignment operators are not deleted,
// so incomplete copy (slicing) is possible.
class boundary_value_condition {

    public:

    // Again, public data 
    int N, T;
    vector<double> v0, v1;
    boundary_value_condition(int N,int T);
    void set_values(const vector<double>& v0, const vector<double>& v1);
    virtual void get_eqn_at_time(double t,vector<double> & X_0,vector<double>& X_N) = 0;

};

class dirichlet_boundary_condition : public boundary_value_condition {
    public:
    dirichlet_boundary_condition(int N,int T);
    virtual void get_eqn_at_time(double t,vector<double> & X_0,vector<double>& X_N);
};

class neumann_boundary_condition : public boundary_value_condition {
    public:
    double dx;
    neumann_boundary_condition(int N,int T,double dx);
    virtual void get_eqn_at_time(double t,vector<double> & X_0,vector<double>& X_N);
};

#endif