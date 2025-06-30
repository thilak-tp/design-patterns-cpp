#include <iostream>
#include <string>
// Factory Design Pattern
// Here we use a factory function to initiate the object depending on the type given by the user

using namespace std;

class Toy{
  protected:
    string name;
    float price;
  public:
    virtual void prepareParts() = 0;
    virtual void combineParts() = 0;
    virtual void assembleParts() = 0;
    virtual void applyLabel() = 0;
    virtual void showProduct() = 0;
};

class Bike : public Toy {
  public:
  void prepareParts() {
    cout<<"Preparing Bike Parts"<<endl;
  }
 
  void combineParts() {
    cout<<"Combining Bike Parts"<<endl;
  }

  void assembleParts() {
    cout<<"Assembling Bike Parts"<<endl;
  }
  void applyLabel() {
    cout<<"Labeling Bike Parts"<<endl; name = "Bike"; price = 10;
  }
  void showProduct() {
    cout<<"Name: "<<name<<" Price:"<<price<<endl;
  }
};

class Car : public Toy {
  public:
  void prepareParts() {
    cout<<"Preparing Car Parts"<<endl;
  }
 
  void combineParts() {
    cout<<"Combining Car Parts"<<endl;
  }

  void assembleParts() {
    cout<<"Assembling Car Parts"<<endl;
  }
  void applyLabel() {
    cout<<"Labeling Car Parts"<<endl; name = "Car"; price = 30;
  }
  void showProduct() {
    cout<<"Name: "<<name<<" Price:"<<price<<endl;
  }
};

class Plane : public Toy {
  public:
  void prepareParts() {
    cout<<"Preparing Plane Parts"<<endl;
  }
 
  void combineParts() {
    cout<<"Combining Plane Parts"<<endl;
  }

  void assembleParts() {
    cout<<"Assembling Plane Parts"<<endl;
  }
  void applyLabel() {
    cout<<"Labeling Plane Parts"<<endl; name = "Plane"; price = 100;
  }
  void showProduct() {
    cout<<"Name: "<<name<<" Price:"<<price<<endl;
  }
};



// Factory Class for Static Factory function to initiate the required class
class ToyFactory {
  public:
  static Toy* createToy(int type) {
    Toy * toy = NULL;
    switch(type) {
       case 1: {
        toy = new Car;
        break;
       }
       case 2 : {
        toy = new Bike;
        break;
       }
       case 3: {
        toy = new Plane;
        break;
       } 
       default: {
        cout<<"Invalid toy type please re-enter type"<<endl;
        return NULL;
       }
    } 

    toy->prepareParts();
    toy->combineParts();
    toy->assembleParts();
    toy->applyLabel();

    return toy;
  }
};

int main() {
  int type = -1;
  

  while(type) {
    cout<<"Enter a type or 0 for exit"<<endl;
    cin>>type;
    if(!type)
      break;
    Toy *tObj = ToyFactory::createToy(type);
    if(tObj) {
      tObj->showProduct();
      delete tObj;
    } 
   
  }
  cout<<"Exit.."<<endl; 
  return 0;
}
