#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout;
using std::cin;
using std::string;
using std::ostringstream;

int main() { 
  cout << "Input filename: ";
  string filename;
  cin >> filename;
  
  // TODO(student): add error checking for width, height, targetWidth, and targetHeight
  int width = 0;
  int height = 0;
  int targetWidth = 0;
  int targetHeight = 0;
  cout << "Input width: ";
  cin >> width;
  	if (cin.fail()) {
		cout << "Error: width is a non-integer value" << std::endl;
		return 0;
	}
	else if (width <= 0) {
		cout << "Error: width must be greater than 0. You entered " << width << std::endl;
		return 0;
	}
	
  cout << "Input height: ";
  cin >> height;
  	if (cin.fail()) {
		cout << "Error: height is a non-integer value" << std::endl;
		return 0;
	}
	else if (height <= 0) {
                cout << "Error: height must be greater than 0. You entered " << height << std::endl;
                return 0;
        }
	
  cout << "Input target width: ";
  cin >> targetWidth;
  	if (cin.fail()) {
		cout << "Error: target width is a non-integer value" << std::endl;
		return 0;
	}
	else if (targetWidth <= 0) {
                cout << "Error: target width must be greater than 0. You entered " << targetWidth << std::endl;
                return 0;
        }
	else if (targetWidth > width) {
		cout << "Error: target width must be less than width, " << targetWidth << " is greater than " << width << std::endl;
		return 0;
	}	
  cout << "Input target height: ";
  cin >> targetHeight;
  	if (cin.fail()) {
		cout << "Error: target height is a non-integer value" << std::endl;
		return 0;
	}
	else if (targetHeight <= 0) {
                cout << "Error: target height must be greater than 0. You entered " << targetHeight << std::endl;
                return 0;
        }
	else if (targetHeight > height) {
		cout << "Error: target height must be less than height, " << targetHeight << " is greater than " << height << std::endl;
		return 0;
	}
  
  // save originalWidth since width will change with carving
  int originalWidth = width; 
	int* verticalSeam = new int[height];
	int* horizontalSeam = new int[width];
  
  Pixel** image1 = createImage(width, height);
  if (image1 != nullptr) { // new returns nullptr if it fails to allocate array

    if (loadImage(filename, image1, width, height)) {
      
      // uncomment for part 2
      
      while ((width - targetWidth > 0) || (height - targetHeight > 0)) {
        if (width - targetWidth > 0) {
          int* verticalSeam = findMinVerticalSeam(image1, width, height);
          removeVerticalSeam(image1, width, height, verticalSeam);
          deleteSeam(verticalSeam);
          width--;
        }
        
        // this is for the extra credit
        if (height - targetHeight > 0) {
          int* horizontalSeam = findMinHorizontalSeam(image1, width, height);
          removeHorizontalSeam(image1, width, height, horizontalSeam);
          deleteSeam(horizontalSeam);
          height--;
        }
      }
      
      
      ostringstream oss;
      oss << "carved" << width << "X" << height << "." << filename;
      outputImage(oss.str().c_str(), image1, width, height);
    } else {
		deleteSeam(verticalSeam);
		deleteSeam(horizontalSeam);
		return 0;
  }
}
  
  // call last to remove the memory from the heap
  deleteImage(image1, originalWidth);
	deleteSeam(verticalSeam);
	deleteSeam(horizontalSeam);
	return 0;
}
