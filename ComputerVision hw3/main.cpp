#include <CImg.h>
#include "histogram.h"
#include "histogramTest.h"
using namespace cimg_library;
int main() {
	CImg<unsigned char> img("C:/Users/shenyi/Pictures/CVhm3/dataset/data0.bmp");
	
	img.display();
	
	//Histogram histimg(img);
	//histimg.getEqualized();
	//histimg.getImg().display();
	//histogramTest test;
	//test.loadDatas("C:/Users/shenyi/Pictures/CVhm3/dataset",12);
	//test.runTest();
	return 0;
}