#include <iostream>

using namespace std;

class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
protected:
	Printer(string mo = "", string me = "", int a = 0) {
		this->model = mo;
		this->manufacturer = me;
		this->availableCount = a;
		this->printedCount = 0;
	}
	bool isValidPrint(int pages) {
		if (availableCount > pages) return true;
		else return false;
	}
	void print(int pages) {
		if (isValidPrint(pages)) {
			printedCount += pages;
			availableCount -= pages;
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void showPrinter() { cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장"; }
};

class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string mo = "", string me = "", int a = 0, int i = 0) : Printer(mo, me, a) { this->availableInk = i; }
	bool isValidInkJetPrint(int pages) {
		if (availableInk > pages) return true;
		else return false;
	}
	void printInkJet(int pages) {
		if (isValidPrint(pages)) {
			if (isValidInkJetPrint(pages)) {
				print(pages);
				availableInk -= pages;
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void showInkJetPrinter() {
		showPrinter();
		cout << ", 남은 토너 " << availableInk << endl;
	}
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string mo = "", string me = "", int a = 0, int t = 0) : Printer(mo, me, a) { this->availableToner = t; }
	bool isValidLaserPrint(int pages) {
		if (availableToner > pages) return true;
		else return false;
	}
	void printInkJet(int pages) {
		if (isValidPrint(pages)) {
			if (isValidLaserPrint(pages)) {
				print(pages);
				availableToner -= pages;
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void showLaserPrinter() {
		showPrinter();
		cout << ", 남은 토너 " << availableToner << endl;
	}
};

int main() {
	InkJetPrinter ink("Officejet V40", "HP", 5, 10);
	LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ink.showInkJetPrinter();
	cout << "레이저 : ";
	laser.showLaserPrinter();

	int printer, paper;
	char ch;
	while (true) {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printer >> paper;
		switch (printer) {
		case 1: ink.printInkJet(paper); break;
		case 2: laser.printInkJet(paper); break;
		default: break;
		}
		ink.showInkJetPrinter();
		laser.showLaserPrinter();

		cout << "게속 프린트 하시겠습니까(y/n)>>";
		cin >> ch;
		if (ch == 'n') break;
		else continue;
	}

	return 0;
}