#pragma once
#include <vector>
#include <string>
using namespace std;
class Financial_instruments {
private:
	double price;
public:
	void set_price(double price) {

	}
};

class stock : public Financial_instruments {
protected:
	string stock_date;
	double open, high, low, close, adj_close;
public:
	stock();
	stock(string date, double open, double high, double low, double close, double adj_close);
	virtual double get_open();
	string get_date();
	double get_adj_close();
	double oneday_updown();
	virtual	void print_info();
	virtual int what_stock_itis() = 0;
	friend bool operator<=(stock&, stock&);
	friend bool operator>=(stock&, stock&);
};




class samsung_stock : public stock {
private:
	double increase_rate = 0;			//이후 vector에서 세팅.
	int volume;
	static double volume_average;
public:
	samsung_stock();
	samsung_stock(string stock_date, double open, double high, double low, double close, double adj_close, int volume, double increase_rate);
	double get_open();
	double get_volume();
	void print_info();
	int what_stock_itis();
	void set_increase_rate(double increase_rate);
	bool compare_average_volume();

};





class apple_stock : public stock {
private:
	double increase_rate;
	int volume;
	double volume_average = 332177847.2;
public:
	apple_stock();
	apple_stock(string stock_date, double open, double high, double low, double close, double adj_close, int volume, double increase_rate);
	double get_open();
	double get_volume();
	void print_info();
	int what_stock_itis();
	void set_increase_rate(double increase_rate);
	bool compare_average_volume();

};

class group_stock {
private:

public:
	vector<stock*> A;
	friend samsung_stock;
	~group_stock();
	void push_back(stock&);
	double RSI(int index);
};



/*
class tesla_stock : public stock {
	double increase_rate;
	double volume;
	double volume_average = 4270740.898;
};

class coin : public Financial_instruments {
private:

};
*/