#include "Financial_instruments.h";
#include <iostream>;
#include <string>;
#include <fstream>
#define SAMSUNG_COUNT 301
#define APPLE_COUNT 301
#define TESLA_COUNT 301


using namespace std;


int main() {
	fstream file;
	string str_buf;

	group_stock all_stock;
	samsung_stock samsung[SAMSUNG_COUNT];
	apple_stock apple[APPLE_COUNT];
	tesla_stock tesla[TESLA_COUNT];
	
	file.open("C:\\Users\\choio\\Downloads\\pl_dataset\\samsung.csv", ifstream::in);
	getline(file, str_buf);
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

		samsung[i] = samsung_stock(stock_date, open, high, low, close, adj_close, volume, 0);
		all_stock.push_back(samsung[i]);

	}
	file.close();

	file.open("C:\\Users\\choio\\Downloads\\pl_dataset\\apple.csv", ifstream::in);
	getline(file, str_buf);
	for (int i = 0; i < APPLE_COUNT - 1; i++) {
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

		apple[i] = apple_stock(stock_date, open, high, low, close, adj_close, volume, 0);
		all_stock.push_back(apple[i]);

	}
	file.close();

	file.open("C:\\Users\\choio\\Downloads\\pl_dataset\\tesla.csv", ifstream::in);
	getline(file, str_buf);
	for (int i = 0; i < TESLA_COUNT - 1; i++) {
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

		tesla[i] = tesla_stock(stock_date, open, high, low, close, adj_close, volume, 0);
		all_stock.push_back(tesla[i]);

	}
	file.close();


	for (int i = 7; i < 897; i++) {
		double AB = all_stock.RSI(i);
		if (AB == 0) {
			continue;
		}
		if (AB > 70) {
			all_stock.A.at(i)->print_info();
			cout << " RSI in " << all_stock.A.at(i - 1)->get_date() << " "<< AB;
			cout << "*매도" << endl;
		}
		else if (AB < 30) {
			all_stock.A.at(i)->print_info();
			cout << " RSI in " << all_stock.A.at(i - 1)->get_date() << " " << AB;
			cout << "*매수" << endl;
		}
	}

}