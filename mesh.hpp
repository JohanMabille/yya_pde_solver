#include <vector>
using std::vector;


#ifndef MESH_HPP
#define MESH_HPP

class mesh {
public:
    // Why is everything public?
    int N;
    double x_0;
    double range;
    
    vector<double> arr[2];

    mesh();
    // Why defining the copy constructor?
    mesh(const mesh& m);
    // The method used to initialize an object is
    // the constructor, it should take these parameters
    // and these methods should be removed
    void init(int N,double x_0,double range);
    void init(const vector<double>& v);
    double get_val_at_index(int i);
    double get_xval(int i);
};

#endif