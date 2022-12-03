#include "Financial_instruments.h";
#include <iostream>
#include <string>
using namespace std;
stock::stock() {
	open = 0;
	high = 0;
	low = 0;
	close = 0;
	adj_close = 0;
}


stock::stock(string date, double open, double high, double low, double close, double adj_close) {
	this->stock_date = date;
	this->open = open;
	this->high = high;
	this->low = low;
	this->close = close;
	this->adj_close = adj_close;
}

double stock::get_open() {
	return open;
}

string stock::get_date() {
	return stock_date;
}
double stock::get_adj_close() {
	return this->adj_close;
}

double stock::oneday_updown() {
	return (this->close - this->open);
}

void stock::print_info() {
	cout << "Stock's";
}

bool operator<=(stock& A, stock& B) {
	bool result;
	if (A.get_adj_close() > B.get_adj_close()) {
		result = 0;
	}
	else {
		result = 1;
	}
	return result;
}

bool operator>=(stock& A, stock& B) {
	bool result;
	if (A.get_adj_close() < B.get_adj_close()) {
		result = 0;
	}
	else {
		result = 1;
	}
	return result;
}

double samsung_stock::volume_average = 21762707.45;

samsung_stock::samsung_stock() {

	this->volume = 0;
}
samsung_stock::samsung_stock(string stock_date, double open, double high, double low, double close, double adj_close, int volume, double increase_rate = 0) {
	this->stock_date = stock_date;
	this->open = open;
	this->high = high;
	this->low = low;
	this->close = close;
	this->adj_close = adj_close;
	this->volume = volume;
	this->increase_rate = increase_rate;
}

double samsung_stock::get_open() {
	return this->open;
}
double samsung_stock::get_volume() {
	return this->volume;
}

void samsung_stock::print_info() {
	cout << "Samsung_stock's" << endl;
}
int samsung_stock::what_stock_itis() {
	return 1;
}

void samsung_stock::set_increase_rate(double increase_rate) {
	this->increase_rate = increase_rate;
}
bool samsung_stock::compare_average_volume() {
	bool result;
	if (this->volume >= samsung_stock::volume_average) {
		result = 1;
	}
	else {
		result = 0;
	}
	return result;
}

apple_stock::apple_stock() {

	this->volume = 0;
}
apple_stock::apple_stock(string stock_date, double open, double high, double low, double close, double adj_close, int volume, double increase_rate = 0) {
	this->stock_date = stock_date;
	this->open = open;
	this->high = high;
	this->low = low;
	this->close = close;
	this->adj_close = adj_close;
	this->volume = volume;
	this->increase_rate = increase_rate;
}

double apple_stock::get_open() {
	return this->open;
}
double apple_stock::get_volume() {
	return this->volume;
}

void apple_stock::print_info() {
	cout << "Apple_stock's" << endl;
}

int apple_stock::what_stock_itis() {
	return 2;
}

void apple_stock::set_increase_rate(double increase_rate) {
	this->increase_rate = increase_rate;
}
bool apple_stock::compare_average_volume() {
	bool result;
	if (this->volume >= apple_stock::volume_average) {
		result = 1;
	}
	else {
		result = 0;
	}
	return result;
}










group_stock::~group_stock() {
	A.clear();
}

void group_stock::push_back(stock& sto) {
	A.push_back(&sto);
}
double group_stock::RSI(int index) {

	double RSI = 0;
	if (index < 7) {
		cout << "wrong index. Please enter >= 7";
		return RSI;
	}
	if (A.at(index - 1)->what_stock_itis() != A.at(index - 6)->what_stock_itis()) {
		cout << "wrong index. You compare different stock.";
		return RSI;
	}
	//A.at(index - 1)->print_info();
	//cout << " RSI in " << A.at(index - 1)->get_date() << endl;
	if (index >= 7) {
		double U = 0, D = 0;
		int U_count = 0, D_count = 0;

		double AU = 0, AD = 0;

		for (int i = 0; i < 6; i++) {
			double A1, B1;
			A1 = A.at(index - 1 - 5 + i)->get_adj_close();
			B1 = A.at(index - 1 - 6 + i)->get_adj_close();
			double temp = A1 - B1;

			if (temp >= 0) {		//╩С╫б
				U += abs(temp);
				U_count++;
			}
			else {																						//го╤Т
				D += abs(temp);
				D_count++;
			}
		}

		AU = U / U_count;
		AD = D / D_count;
		RSI = AU / (AU + AD);
		
	}
	return RSI * 100;
}