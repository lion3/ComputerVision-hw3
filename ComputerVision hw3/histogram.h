#pragma once
#ifndef _HISTOGRAM_
#define _HISTOGRAM_
#include <CImg.h>
#include <vector>
#include <iostream>
using namespace cimg_library;
using namespace std;
class Histogram {
private:
	CImg<unsigned char> img;
	int channel;
	int level = 255;

	vector<vector<double> > pdf();
	vector<vector<double> > cdf();
	vector<vector<int> > transfer();
	void histogram_equalization();

public:
	Histogram(CImg<unsigned char> _img);
	void getEqualized();
    CImg<unsigned char> getImg();

};
#endif