#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Date {
public:
	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
	Date(int, int, int);
private:
	int day{ 0 };
	int month{ 0 };
	int year{ 1900 };
};

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

class Transaction {
public:
	double get_value() { return value; }
	string get_name() { return name; }
	Date get_date() { return date; }
	Transaction(double, string, Date);
private:
	double value{ 0 };
	string name{ "" };
	Date date = Date(12, 03, 1990);
};

Transaction::Transaction(double v, string n, Date d) {
	value = v;
	string name = n;
	Date date = d;
}

class Account {
public:
	double total_spent();
	string most_frequent_transaction();
	string largest_single_transaction();
	string largest_expense();
	void add_transaction(Transaction t) { statement.push_back(t); }
private:
	vector<Transaction>statement;
	string acct_name{ "" };
};

double Account::total_spent() {
	double sum{ 0 };
	for (Transaction t : statement ) {
		if (t.get_value() < 0) {
			sum += abs(t.get_value());
		}
	}
	return sum;
}

int main() {
	Account a = Account();
	Date d = Date(01, 06, 2001);
	Transaction t(-5.00, "ATM", d);
	Transaction i(-7.00, "ATM", d);
	a.add_transaction(t);
	a.add_transaction(i);
	cout << "Total spent: GBP " << a.total_spent() << '\n';
	cout << t.get_date(); << " " << i.get_date() << '\n';
	return 0;
 }