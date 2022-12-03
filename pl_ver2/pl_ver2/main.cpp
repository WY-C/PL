#include "Financial_instruments.h";
#include <iostream>;
#include <string>;
#include <fstream>
#define SAMSUNG_COUNT 5622


using namespace std;


int main() {
	fstream file;
	string str_buf;

	file.open("C:\\Users\\Choi\\Desktop\\pl_dataset\\samsung.csv", ifstream::in);
	getline(file, str_buf);

	group_stock all_stock;
	samsung_stock temp[SAMSUNG_COUNT];
	for (int i = 0; i < SAMSUNG_COUNT - 1; i++) {
		string stock_date;
		double open, high, low, close, volume;
		double adj_close;

		getline(file, str_buf, ',');
		stock_date = str_buf;

		getline(file, str_buf, ',');
		open = stod(str_buf);

		getline(file, str_buf, ',');
		high = stod(str_buf);

		getline(file, str_buf, ',');
		low = stod(str_buf);

		getline(file, str_buf, ',');
		close = stod(str_buf);

		getline(file, str_buf, ',');
		adj_close = stod(str_buf);

		getline(file, str_buf, '\n');
		volume = stod(str_buf);

		temp[i] = samsung_stock(stock_date, open, high, low, close, adj_close, volume, 0);
		all_stock.push_back(temp[i]);

	}

	for (int i = 7; i < SAMSUNG_COUNT - 1; i++) {
		double AB = all_stock.RSI(i);
		if (AB > 70) {
			cout << "RSI in " << all_stock.A.at(i - 1)->get_date() << " "<< AB;
			cout << "*매도" << endl;
		}
		else if (AB < 30) {
			cout << "RSI in " << all_stock.A.at(i - 1)->get_date() << " " << AB;
			cout << "*매수" << endl;
		}
	}

}