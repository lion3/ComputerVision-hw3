#include <CImg.h>
#include "histogram.h"
#include "histogramTest.h"
using namespace cimg_library;
int main() {
	string filepath;
	cin >> filepath;
	CImg<unsigned char> img(filepath.data());
	
	img.display();
	return 0;
}