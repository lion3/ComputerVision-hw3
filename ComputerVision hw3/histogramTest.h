#pragma once
#ifndef _HISTOGRAMTEST_
#define _HISTOGRAMTEST_
#include "histogram.h"
#include <string>
using namespace std;
class histogramTest
{
public:
	histogramTest();
	~histogramTest();
	void loadDatas(string _path,int _size);
	void runTest();

private:
	int size = 0;
	string savepath ="";
	CImg<unsigned char>  RGBTest(Histogram target);
	CImg<unsigned char>  GrayTest(Histogram target);
	vector<Histogram> testColorDatas;
	vector<Histogram> testGrayDatas;
};


#endif