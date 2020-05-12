#include <cassert>
#include <stdexcept>
#include <math.h>
#include <iostream>

using std::cout;

// TODO: Define class Pyramid
class Pyramid{
    //attributes
    private:
    int length;
    int width;
    int height;
    float Volume;
    float SurfaceArea;

    public:
    Pyramid(int len, int wid, int hei):length(len), width(wid), height(hei){(len<0||wid<0||hei<0)?throw std::invalid_argument("Inappropriate value"): 1;};
    //setters
    void sLength(int len);
    void sWidth(int wid);
    void sHeight(int hei);
    void sVolume(int len, int wid, int hei);
    void sSurfaceArea(int len, int wid, int hei);

    //getters
    int gLength() const;
    int gWidth() const;
    int gHeight() const; 
    float gVolume();
    float gSurfaceArea();
};
//defining setters
void Pyramid::sLength(int len){Pyramid::length = len;}
void Pyramid::sWidth(int wid){Pyramid::width = wid;}
void Pyramid::sHeight(int hei){Pyramid::height = hei;}
void Pyramid::sVolume(int len, int wid, int hei){
    Pyramid::Volume = len*wid*hei/3;
}
void Pyramid::sSurfaceArea(int len, int wid, int hei){
    Pyramid::SurfaceArea = wid*len+len*sqrt(0.5*wid*0.5*wid+hei*hei)+wid*sqrt(0.5*len*0.5*len+hei*hei);
}
//defining getters
int Pyramid::gLength() const{return Pyramid::length;}
int Pyramid::gWidth() const{return Pyramid::width;}
int Pyramid::gHeight() const{return Pyramid::height;}
float Pyramid::gVolume() {return Pyramid::Volume;}
float Pyramid::gSurfaceArea(){return Pyramid::SurfaceArea;}

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.gLength() == 4);
  assert(pyramid.gWidth() == 5);
  assert(pyramid.gHeight() == 6);
  pyramid.sVolume(pyramid.gLength(),pyramid.gWidth(),pyramid.gHeight());
  assert(pyramid.gVolume() == 40);
  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught); 
}