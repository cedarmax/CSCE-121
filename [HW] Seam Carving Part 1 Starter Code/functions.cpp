#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

#define INFO(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;

using std::cout;
using std::endl;
using std::string;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //	that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
	// assign that column to a one dimensional array on the heap of Pixels
	//	that has height elements (i.e. the number of rows)
	image[i] = new Pixel[height];
	
	if (image[i] == nullptr) { // failed to allocate
	  fail = true;
	}
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
	// deallocate any arrays created in for loop
	for (int i=0; i < width; ++i) {
	  delete [] image[i]; // deleting nullptr is not a problem
	}
	delete [] image; // dlete array of pointers
	return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
	for (int col=0; col<width; ++col) {
	  //cout << "(" << col << ", " << row << ")" << endl;
	  image[col][row] = { 0, 0, 0 };
	}
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
	delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

int* createSeam(int length) {
	// TODO(student): create a seam
//	INFO(length);
	int *array = new int[length];
	for (int i = 0; i < length; ++i) {
		array[i] = 0;
	}
	return array;
	
  return nullptr;
}

void deleteSeam(int* seam) {
	// TODO(student): delete a seam
//	INFO(seam);
	delete [] seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) {
	// TODO(student): load an image
//	INFO(filename);
//	INFO(image);
//	INFO(width);
//	INFO(height);
	cout << "Loading image..." << endl;
  // declare/define and open input file stream
  std::ifstream ifs (filename);
  
  // check if input stream opened successfully
  if (!ifs.is_open()) {
	cout << "Error: failed to open input file - " << filename << endl;
	return false;
  }
  
  // get type from preamble
  char type[3];
  ifs >> type; // should be P3
  if ((toupper(type[0]) != 'P') || (type[1] != '3')) { // check that type is correct
	cout << "Error: type is " << type << " instead of P3" << endl;
	return false;
  }
  
  // get width (w) and height (h) from preamble
  int w = 0, h = 0;
  ifs >> w;
	 if (ifs.fail()) {
	cout << "Error: read non-integer value";
	return false;
} else if (w != width) { // check that width matches what was passed into the function
	cout << "Error: input width (" << width <<	") does not match value in file (" << w << ")" << endl;
	cout << " - input width: " << width << endl;
	cout << " -  file width: " << w << endl;
	return false;
  }
	ifs >> h;
	 if (ifs.fail()) {
	cout << "Error: read non-integer value";
	return false;
} else if (h != height) { // check that height matches what was passed into the function
	cout << "Error: input height (" << height << ") does not match value in file (" << h << ")" << endl;
	cout << " - input height: " << height << endl;
	cout << " -  file height: " << h << endl;
	return false;
  } 
  
  // get maximum value from preamble
  int colorMax = 0;
  ifs >> colorMax;
  if (colorMax != 255) {
	cout << "Error: file is not using RGB color values." << endl;
	return false;
  }

  // TODO(student): get RGB pixel values
	int tooMany;
  for (int j = 0; j < height; ++j) {
	for (int i = 0; i < width; ++i) {
		ifs >> image[i][j].r;
		if ((image[i][j].r < 0) or (image[i][j].r > 255)) {
			cout << "Error: invalid color value " << image[i][j].r;
			return false;
		} else if (ifs.eof() and ifs.fail()) {
			cout << "Error: not enough color values";
			return false;
		} else if (ifs.fail()) {
			cout << "Error: read non-integer value";
			return false;
		}
		ifs >> image[i][j].g;
	    if ((image[i][j].g < 0) or (image[i][j].g > 255)) {
			cout << "Error: invalid color value " << image[i][j].g;
			return false;
		} else if (ifs.eof() and ifs.fail()) {
			cout << "Error: not enough color values";
			return false;
		} else if (ifs.fail()) {
			cout << "Error: read non-integer value";
			return false;
		}
		ifs >> image[i][j].b;
		if ((image[i][j].b < 0) or (image[i][j].b > 255)) {
			cout << "Error: invalid color value " << image[i][j].b;
			return false;
		} else if (ifs.eof() and ifs.fail()) {
			cout << "Error: not enough color values";
			return false;
		} else if (ifs.fail()) {
			cout << "Error: read non-integer value";
			return false;
		}
	}
  }
	if (ifs.eof()) {
		return true;
	} else {
		ifs >> tooMany;
		if (ifs.fail()) {
			return true;
		} else {
			cout << "Error: too many color values";
			return false;
		}
	}
 
  return true;
}

bool outputImage(string filename, Pixel** image, int width, int height) {
	// TODO(student): output an image
//	INFO(filename);
//	INFO(image);
//	INFO(width);
//	INFO(height);
cout << "Outputting image..." << endl;
  // TODO(student): declare/define and open output file stream
  
  // TODO(student): check if output stream opened successfully
  
  // TODO(student): output preamble
  
  // TODO(student): output pixels
  std::ofstream ofs (filename);
  if (!ofs.is_open()) {
	cout << "Error: failed to open input file " << filename << endl;
	return false;
  }
  ofs << "P3"<< endl; 
  ofs << width << " " << height << endl; 
  ofs << 255 << endl; 
  for (int j = 0; j < height; ++j) {
	for (int i = 0; i < width; ++i) {
		ofs << image[i][j].r << " " << image[i][j].g << " " << image[i][j].b << " ";
	}
	ofs << endl;
  }

  return true;
}

int energy(Pixel** image, int column, int row, int width, int height) { 
	// TODO(student): compute the energy of a pixel
//	INFO(image);
//	INFO(column);
//	INFO(row);
//	INFO(width);
//	INFO(height);

	int rxd,gxd,bxd;
	int ryd,gyd,byd;
   	int sumXdelta, sumYdelta;
	int lowerXbound, lowerYbound, upperXbound, upperYbound;
	lowerXbound = column - 1;
	lowerYbound = row - 1;
	upperXbound = column + 1;
	upperYbound = row + 1;
	if (row + 1 > height - 1) { //bottom edge case
		upperYbound = 0;
	}
	if (column + 1 > width - 1) { //right edge case
		upperXbound = 0;
	}
	if (row == 0) { //top edge case
		lowerYbound = height - 1;
	}
	if (column == 0) { //left edge case
		lowerXbound = width - 1;
	}
	//middle pixel code:
	rxd = abs(image[lowerXbound][row].r-image[upperXbound][row].r);
    gxd = abs(image[lowerXbound][row].g-image[upperXbound][row].g);
	bxd = abs(image[lowerXbound][row].b-image[upperXbound][row].b);
	ryd = abs(image[column][lowerYbound].r-image[column][upperYbound].r);
	gyd = abs(image[column][lowerYbound].g-image[column][upperYbound].g);
	byd = abs(image[column][lowerYbound].b-image[column][upperYbound].b);
	
	sumXdelta = pow(rxd, 2) + pow(gxd, 2) + pow(bxd, 2);
	sumYdelta = pow(ryd, 2) + pow(gyd, 2) + pow(byd, 2);
	//cout << "sumXdelta: " << sumXdelta << endl;
	//cout << "sumYdelta: " << sumYdelta << endl;
	//cout << "energy: " << sumXdelta+sumYdelta << endl;

	return sumXdelta + sumYdelta;
}

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
	// TODO(student): load a vertical seam
//	INFO(image);
//	INFO(start_col);
//	INFO(width);
//	INFO(height);
//	INFO(seam);
	int left = INT32_MAX;
	int center = INT32_MAX;
	int right = INT32_MAX;
	int totalEnergy = energy(image, start_col, 0, width, height);
	seam[0] = start_col;

	for (int i = 1; i < height; i++) {
		if (width == 1) {
			center = energy(image, start_col, i, width, height);
		} else if ((start_col == 0) and (width != 1)) {
			center = energy(image, start_col, i, width, height);
			right = energy(image, start_col + 1, i, width, height);
			left = center + right;
		} else if (start_col == width - 1) {
			left = energy(image, start_col - 1, i, width, height);
			center = energy(image, start_col, i, width, height);
			right = left + center;
		} else {
			right = energy(image, start_col + 1, i, width, height);
			center = energy(image, start_col, i, width, height);
			left = energy(image, start_col - 1, i, width, height);
		}
		
		if (width == 1) {
			seam[i] = start_col;
			totalEnergy += center;
		} else if ((left < right) && (left < center)) {
			--start_col;
			seam[i] = start_col;
			totalEnergy += left;
		} else if ((center < left) && (center < right)) {
			seam[i] = start_col;
			totalEnergy += center;
		} else if ((right < center) && (right < left)) {
			++start_col;
			seam[i] = start_col;
			totalEnergy += right;
		} else if ((left == center) && (left < right)) {
			seam[i] = start_col;
			totalEnergy += center;
		} else if ((center == right) && (center < left)) {
			seam[i] = start_col;
			totalEnergy += center;
		} else if ((right == left) && (right < center)) {
			++start_col;
			seam[i] = start_col;
			totalEnergy += right;
		} else if ((left == center) && (center == right)) {
			seam[i] = start_col;
			totalEnergy += center;
		}
	}
	return totalEnergy;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
	// TODO(student): load a horizontal seam
//	INFO(image);
//	INFO(start_row);
//	INFO(width);
//	INFO(height);
//	INFO(seam);
	int left = INT32_MAX;
	int center = INT32_MAX;
	int right = INT32_MAX;
	int totalEnergy = energy(image, 0, start_row, width, height);
	seam [0] = start_row;

	for (int i = 1; i < width; i++) {
		if (height == 1) {
			center = energy(image, i, start_row, width, height);
		} else if ((start_row == 0) and (height != 1)) {
			center = energy(image, i, start_row, width, height);
			right = energy(image, i, start_row + 1, width, height);
			left = center + right;
		} else if (start_row == height - 1) {
			left = energy(image, i, start_row - 1, width, height);
			center = energy(image, i, start_row, width, height);
			right = left + center;
		} else {
			left = energy(image, i, start_row - 1, width, height);
			center = energy(image, i, start_row, width, height);
			right = energy(image, i, start_row + 1, width, height);
		}

		if (height == 1) {
			seam[i] = start_row;
			totalEnergy += center;
		} else if ((left < center) && (left < right)) {
			--start_row;
			seam[i] = start_row;
			totalEnergy += left;
		} else if ((center < left) && (center < right)) {
			seam[i] = start_row;
			totalEnergy += center;
		} else if ((right < left) && (right < center)) {
			++start_row;
			seam[i] = start_row;
			totalEnergy += right;
		} else if ((left == center) && (left < right)) {
			seam[i] = start_row;
			totalEnergy += center;
		} else if ((center == right) && (center < left)) {
			seam[i] = start_row;
			totalEnergy += center;
		} else if ((right == left) && (right < center)) {
			--start_row;
			seam[i] = start_row;
			totalEnergy += right;
		} else if ((left == center) && (center == right)) {
			seam[i] = start_row;
			totalEnergy += center;
		}
//		cout << "Center: " << center << endl;
//		cout << "Right: " << right << endl;
//		cout << "Left: " << left << endl;
//		cout << "start_row: " << start_row << endl;
//		cout << "seam[i]: " << seam[i] << endl;
//		cout << "totalEnergy: " << totalEnergy << endl;
	}
  return totalEnergy;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
	// TODO(student): find min vertical seam
//	INFO(image);
//	INFO(width);
//	INFO(height);
	int* minSeam = new int[height];
	int* seam = new int[height];
	int minEnergy, currEnergy;

	minEnergy = loadVerticalSeam(image, 0, width, height, seam);
	currEnergy = -1;

	for (int i = 0; i < height; i++) {
		minSeam[i] = seam[i];
	}

	for (int i = 1; i < width; i++) {
		currEnergy = loadVerticalSeam(image, i, width, height, seam);
		if (currEnergy < minEnergy) {
			minEnergy = currEnergy;
			for (int i = 0; i < height; i++) {
				minSeam[i] = seam[i];
			}
		}
	}
	deleteSeam(seam);
	seam = nullptr;
  return minSeam;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
	// TODO(student): find min horizontal seam
//	INFO(image);
//	INFO(width);
//	INFO(height);
	int* minSeam = new int[width];
	int* seam = new int[width];
	int minEnergy, currEnergy;

	minEnergy = loadHorizontalSeam(image, 0, width, height, seam);
	currEnergy = -1;

	for (int i = 0; i < width; i++) {
		minSeam[i] = seam[i];
	}

	for (int i = 1; i < height; i++) {
		currEnergy = loadHorizontalSeam(image, i, width, height, seam);
		if (currEnergy < minEnergy) {
			minEnergy = currEnergy;
			for (int i = 0; i < width; i++) {
				minSeam[i] = seam[i];
			}
		}
	}
	deleteSeam(seam);
	seam = nullptr;
  return minSeam;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
	// TODO(student): remove a vertical seam
//	INFO(image);
//	INFO(width);
//	INFO(height);
//	INFO(verticalSeam);
	Pixel temp;

	for (int i = 0; i < height; i++) {
		temp = image[verticalSeam[i]][i];

		for (int j = verticalSeam[i]; j < width - 1; j++) {
			image[j][i] = image[j + 1][i];
		}
		image[width - 1][i] = temp;
	}
}

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
	// TODO(student): remove a horizontal seam
//	INFO(image);
//	INFO(width);
//	INFO(height);
//	INFO(horizontalSeam);
	Pixel temp;

	for (int i = 0; i < width; i++) {
		temp = image[i][horizontalSeam[i]];

		for (int j = horizontalSeam[i]; j < height - 1; j++) {
			image[i][j] = image[i][j + 1];
		}
		image[i][height - 1] = temp;
	}
}	

