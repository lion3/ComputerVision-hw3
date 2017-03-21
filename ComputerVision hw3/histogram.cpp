#include "histogram.h"



	vector<vector<double> >  Histogram::pdf() {
		vector<vector<double> > _pdf;
		for (int i = 0; i < channel; i++) {
			unsigned int val[256];
			for (int j = 0; j < 256; j++) {
				val[j] = 0;
			}

			for (int x = 0; x < img.width(); x++) {
				for (int y = 0; y < img.height(); y++) {

					// Q here
					unsigned char t = img(x, y, 0, i);

					val[t] += 1;
				}
			}
			vector<double> hist;
			double imgsize = img.height()*img.width();
			for (int j = 0; j < 256; j++) {
				hist.push_back(val[j] / imgsize);
			}
			_pdf.push_back(hist);
		}
		return _pdf;
	}
	vector<vector<double> >  Histogram::cdf() {
		vector<vector<double> > _pdf = pdf();
		vector<vector<double> > _cdf;
		for (int i = 0; i < channel; i++) {
			vector<double> hist = _pdf[i];
			for (int j = 1; j < hist.size(); j++) {
				hist[j] += hist[j - 1];
			}
			_cdf.push_back(hist);
		}
		return _cdf;
	}
	vector<vector<int> >  Histogram::transfer() {
		vector<vector<double> > _cdf = cdf();
		vector<vector<int>>  transfer;
		for (int i = 0; i < channel; i++) {

			vector<double> hist = _cdf[i];

			vector<int> T;
			for (int j = 0; j < hist.size(); j++) {
				T.push_back((int)roundl(hist[j] * level));
			}
			transfer.push_back(T);
		}
		return transfer;
	}
	void  Histogram::histogram_equalization() {
		cout << channel;
		vector<vector<int> >  _transfer = transfer();
		for (int i = 0; i < channel; i++) {
			vector<int> T = _transfer[i];
			for (int x = 0; x < img.width(); x++) {
				for (int y = 0; y < img.height(); y++) {
					unsigned char t = img(x, y, 0, i);
					img(x, y, 0, i) = T[t];
				}
			}

		}

	}


	Histogram::Histogram(CImg<unsigned char> _img) {
		img = _img;
		channel = img.spectrum();

	}

	void  Histogram::getEqualized() {
		histogram_equalization();
	}
	CImg<unsigned char>  Histogram::getImg() {
		return img;
	}

	
