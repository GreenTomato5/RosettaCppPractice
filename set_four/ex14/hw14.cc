// In this exercise, you will be working with classes and derived classes.
// Inheritance is an important concept in object-oriented design
// because it allows us to define one class in terms of another class.
// Conceptually, one class ought to derive from another class if it passes
// the "is a" test.  If you can say X is a Y, then X should derive from Y.
// For instance, a "Dog" is a "Mammal".  It would be appropriate to encode
// this relationship by by creating a "Dog" class as a derivative of
// the "Mammal" class.

// Here are a few references to get you started on this concept:
// http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
// http://en.wikibooks.org/wiki/C%2B%2B_Programming/Classes/Inheritance

// For this exercise, we can think of a "triangle" and a "rectangle" as
// derivatives of the parent class "shape".

// Your mission, should you choose to accept it, will be to define two classes
// circle and triangle that will calculate the area of a circle and a triangle.
// This area will be stored in a private member variable defined in the
// parent class "shape", which will only be accessible by the base classe's get_area
// and set_area functions. You will test your new derived classes by creating
// instances of each in main() and printing their areas.

// Question (Answer here):
// Why does the whats_area() function in the rectangle class generate an error?

// For Homework 14, You should create a separate cc file that contains your base
// and derived classes. For this exercise, you should add a pure virtual function
// to the base class called "name", which returns a string giving the name for the
// class. You'll use this to make reporting the areas of your objects easier: you
// can construct a std::vector< shape * > and load up the individual instances
// (constructed using "new" and put into pointers) into this vector.  Then you can
// use a for loop to visit each shape and to output its name and its area.  The
// output should remain identical to that in hw13, but it should come from a for loop
// instead of from individual cout statements.


#include <iostream>
#include <vector>

class shape {
public:
  float get_area(){return area_;} //Getter function: returns the area stored in area_
  void set_name(std::string name) {name_ = name;}
  std::string get_name() {return name_;}

protected:

  // Setter function: changes the value of the area stored in area_
  // what does it meant that this function is protected?
  float set_area(float a){area_ = a;} 

private:
  float area_;
  std::string name_;
};

//write a derived class rectangle from the base class shape
class rectangle : public shape{
public:
  // note that the rectangle is responsible for informing the base class of its area
  rectangle( float b, float h ) { base_ = b; height_ = h; set_area( calculate_area() ); set_name("Rectangle");} //constructor that sets-up default values

  float calculate_area() {return base_ * height_;} //calculates the area of a rectangle using the formula base*height

  // It doesent compile because area is a private member of shape and rectangle cant derive area from shape because it
  // only inherits publically
  //float whats_area(){return area_;} //THIS LINE WILL NOT COMPILE. Why not?

  void set_base( float b ) { base_ = b; set_area( calculate_area() ); }
  void set_height( float h ) { height_ = h; set_area( calculate_area() ); }

private:
  float base_;
  float height_;
};

// Write a derived class, circle, from the base class shape. A circle can be defined
// by a single radius and thus the constructor should take a single argument and assign
// the value to the radius. There should also be a calculate_area function that
// calculates the area of the circle.
class Circle : public shape {
public:
  Circle(float r) {radius_ = r; set_area(calculate_area()); set_name("Circle");}

  void set_radius(float r) {radius_ = r; set_area(calculate_area());}

private:
  float radius_;
  float calculate_area() {return 3.14159265359 * radius_ * radius_;}
};


// Write a derived class, triangle, from the base class shape.  A triangle can be
// defined by the lengths of its three sides.  Make sure your triangle is able to
// calculate its area.  If the three lengths do not define a proper triangle (e.g.
// if one lenght is 1 another length is 2 and the third length is 100, then you
// don't have a closed triangle), then set the area to be -1.

class Triangle : public shape {
public:
  Triangle(float l1, float l2, float l3) {
    if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1) {
      length1_ = l1;
      length2_ = l2;
      length3_ = l3;
      set_area(calculate_area());
    } else {
      set_area(-1);
    }
    set_name("Triangle");
  }

private:
  float length1_;
  float length2_;
  float length3_;

  float calculate_area() {
    float s = (length1_ + length2_ + length3_) / 2;
    return sqrt(s * (s - length1_) * (s - length2_) * (s - length3_));
  }

};

int main(){
  
  float user_base, user_height;

  std::cout << "Please enter a base length: ";
  std::cin >> user_base;
  std::cout << "Please enter a height: ";
  std::cin >> user_height;

  //Create rectangle object and put it into the vector of shape *'s
  // this line will not work, but it's close: rectangle rec1(user_base, user_height);


  //Test your circle class
  float user_radius;
  std::cout << "Please enter a circle radius: ";
  std::cin >> user_radius;

  //create an object of the circle class with radius equal to user_radius
  
  // Test your triangle class
  float length1, length2, length3;
  std::cout << "Please enter length 1 for your triangle: ";
  std::cin >> length1;
  std::cout << "Please enter length 2 for your triangle: ";
  std::cin >> length2;
  std::cout << "Please enter length 3 for your triangle: ";
  std::cin >> length3;

  // create an object of the triangle class with the three lengths.
  // Your triangle class should probably make sure that these lengths
  // are sensical.  (do the distances satisfy the "triangle inequality"?)
  std::vector<shape*> shapes;
  shapes.push_back(new rectangle(user_base, user_height));
  shapes.push_back(new Circle(user_radius));
  shapes.push_back(new Triangle(length1, length2, length3));

  // Replace the following statements with a for loop
  // std::cout << "The area of the rectangle is: " << rec1->get_area() << std::endl;
  // std::cout << "The area of the circle is: " << std::endl;
  // std::cout << "The area of the triangle is: " << std::endl;

  // Now iterate across the vector and delete all the objects pointed to by it;
  // you should not leak memory.

  for (shape * s : shapes) {
    std::cout << "The area of the " << s->get_name() << " is: " << s->get_area() << std::endl;
    delete s;
  }

  return 0;

}
