#include <iostream>

int main() {
  
  std::cout << "Enter the pine tree's height as an integer: ";
  int height;
  std::cin >> height;

  // Tree leafs
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < height - i - 1; j++) {
      std::cout << " ";
    }
    for (int k = 0; k < 2 * i + 1; k++) {
      std::cout << "*";
    }
    std::cout <<  std::endl;
  }

  // Branch at bottom
  for (int i = 0; i < (height - 1); i++) {
    std::cout << " ";
  }
  std::cout << "|" << std::endl;

  // Assignment:
  // Write code here to draw a pine tree.
  // If the height given is "3" then the pine tree should look like this:
  //   *
  //  ***
  // *****
  //   |
  //
  // If the height given is "5" then the pine tree should look like this:
  //     *
  //    ***
  //   *****
  //  *******
  // *********
  //     |
  //
  // where the height represents the number of rows of stars.  The trunk should
  // always be there.  Don't worry about writing code to verify that the input
  // is an integer (though, kudos if you did think about that being necessary!)

  return 0;
}
