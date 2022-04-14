#include <iostream>

class shape {
    protected:
        double length;
        double height;
    public:
    // default constructor (no arguments)
    shape(){
        length = 0.0;
        height = 0.0;
    }
    // constructor
    shape(double height, double length) {
        this->length = length;
        this->height = height;
    }

    virtual double area(){
        return this->height*this->length;
    }

    void setHeight(double newH){height = newH;}
    void setLength(double newL){length = newL;}
    double& getHeight(){return height;}
    double& getLength(){return length;}

};

class rectangle : public shape{
 public:
 //default constructor
 rectangle(): shape(){}
 
 rectangle(double height) {
     this->height = height;
 }
 
rectangle(double height, double length):
 shape (height, length){}


};

class square: public rectangle{
    public:
      square(): rectangle(){}
      square(double size): rectangle(size,size){}
};

class triangle : public shape{
    public:
    triangle(double height, double length): 
        shape(height, length){
            
        }
    virtual double area(){               //do we need virtual here? same question here?
        return 0.5*(this->height*this->length);
    }
};

int main(){

    shape s(10,20);
    std::cout<<"Area is "<<s.area()<<std::endl;
    double& h = s.getHeight();
    h = 100;
    std::cout<<"Area is "<<s.area()<<std::endl;
    
shape* l = new triangle(10,20);    
std::cout<<"Area is "<<l->area()<<std::endl;
delete l;


l= new rectangle(10,20);
delete l;

std::cout<<"Area is "<<l->area()<<std::endl;
    
    return 0;
}