#include "histogramTest.h"
 void histogramTest::loadDatas(string  _path,int _size)
{
	string path = _path;
	savepath = _path + "/save";
	string format = "/data";
	string type = ".jpg";
	size = _size;
	for (int i = 0; i < size; i++) {
		string temp = path + format + to_string(i) + type;
		CImg<unsigned char> img(temp.data());
		Histogram T1(img);
		Histogram T2(img.get_RGBtoGray());
		testColorDatas.push_back(T1);
		testGrayDatas.push_back(T2);
	}
}

 void histogramTest::runTest()
 {
	 for (int i = 0; i < size; i++) {
		 string rgbsave = savepath + "/rgbtest"+to_string(i)+".jpg";
		 string graysave = savepath + "/graytest" + to_string(i) + ".jpg";
		 RGBTest(testColorDatas[i]).save(rgbsave.data());
		 GrayTest(testGrayDatas[i]).save(graysave.data());
	 }
	
 }

 CImg<unsigned char>  histogramTest::RGBTest(Histogram target)
 {
	 target.getEqualized();

	 return target.getImg();
 }

 CImg<unsigned char>  histogramTest::GrayTest(Histogram target)

 {
	 target.getEqualized();

	 return target.getImg();
 }
 histogramTest::histogramTest()
 {

 }

 histogramTest::~histogramTest()
 {
 }
