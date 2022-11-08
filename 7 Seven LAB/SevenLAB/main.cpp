#include <iostream>
#include <time.h>

using namespace std;

const int K = 22;
const int R = 3;

//--------------------------------------------------------------------------------------------

class figure
{
public:
    double *geometry;
    virtual void print(ostream &out) const = 0;
    friend ostream& operator<< (ostream& out , figure const& figure);
    ~figure(){
        delete [] geometry;
    }
};

//--------------------------------------------------------------------------------------------

class rectangle : public figure
{
public:
    rectangle(int R){
        geometry = new double[4];
        geometry[2] = rand()%(100*R); // ширина
        geometry[3] = rand()%(100*R); // высота
        geometry[0] = (geometry[2]/2) + (rand()%(100*R - (int)geometry[2])); // x
        geometry[1] = (geometry[3]/2) + (rand()%(100*R - (int)geometry[3])); // y
    }
    void print(ostream &out) const override {
        out << "Rectangle " << endl << " x = " << geometry[0]  << ", y=" << geometry[1]<<
                endl<< "Width: " << geometry[2] << endl << "Height: " << geometry[3];
    }
};

//--------------------------------------------------------------------------------------------

class circle : public figure
{
public:
    circle(int R){
        geometry = new double[3];
        geometry[2] = rand()%(100*R); // Радиус
        geometry[0] = (geometry[2]/2) + (rand()%(100*R - (int)geometry[2])); // x
        geometry[1] = (geometry[2]/2) + (rand()%(100*R - (int)geometry[2])); // y
    }
    void print(ostream &out) const override {
        out << "Circle " << endl << " x = " << geometry[0]  << ", y=" << geometry[1]<<
                endl<< "Radius: " << geometry[2];
    }
};

//--------------------------------------------------------------------------------------------

ostream& operator<< (ostream& out, const figure &figure){
    figure.print(out);
    return out;
};

double xrand (double rmin, double rmax){
    double z;
    z = rmin + ((double)rand()/RAND_MAX)*(rmax-rmin);
    return z;
}

//--------------------------------------------------------------------------------------------

int main(){
    srand(time(NULL));
    figure *arr[K];
    for(int i = 0; i < K; i++){
        if(xrand(0,1)>0.5){
            arr[i] = new rectangle(R);
        }
        else{
            arr[i] = new circle(R);
        }
    }
    for(int i = 0; i < K; i++){
        cout << *arr[i] << "\n\n";
    }
    return 0;
}

