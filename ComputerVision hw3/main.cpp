#include <CImg.h>
#include "histogram.h"
#include "histogramTest.h"
using namespace cimg_library;
int main() {
	cout << "please cin a file name\n";
	string filepath;
	cin >> filepath;
	CImg<unsigned char> img(filepath.data());
	img.display();
	histogramTest test;
	test.loadDatas("C:/Users/xusy/Pictures/CVHW3/dataset",10);
	test.runTest();
	return 0;
}