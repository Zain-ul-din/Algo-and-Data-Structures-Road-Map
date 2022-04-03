#include<iostream>
#include<string>
using namespace std;
class Evolution
{
private:
	int paper1, paper2, paper3, paper4, paper5, average;
	double percent1, percent2, percent3, percent4, percent5;
public:
	void set_paper1(int paper1)
	{
		this->paper1 = paper1;
	}
	int get_paper1()
	{
		return this->paper1;
	}
	void set_paper2(int paper2)
	{
		this->paper2 = paper2;
	}
	int get_paper2()
	{
		return this->paper2;
	}
	void set_paper3(int paper3)
	{
		this->paper3 = paper3;
	}
	int get_paper3()
	{
		return this->paper3;
	}
	void set_paper4(int paper4)
	{
		this->paper4 = paper4;
	}
	int get_paper4()
	{
		return this->paper4;
	}
	void set_paper5(int paper5)
	{
		this->paper5 = paper5;
	}
	int get_paper5()
	{
		return this->paper5;
	}
	void set_average(int average)
	{
		this->average = average;
	}
	int get_average()
	{
		return this->average;
	}
	void set_percent1(double percent1)
	{
		this->percent1 = percent1;
	}
	double get_percent1()
	{
		return this->percent1;
	}
	void set_percent2(double percent2)
	{
		this->percent2 = percent2;
	}
	double get_percent2()
	{
		return this->percent2;
	}
	void set_percent3(double percent3)
	{
		this->percent3 = percent3;
	}
	double get_percent3()
	{
		return this->percent3;
	}
	void set_percent4(double percent4)
	{
		this->percent4 = percent4;
	}
	double get_percent4()
	{
		return this->percent4;
	}
	void set_percent5(double percent5)
	{
		this->percent5 = percent5;
	}
	double get_percent5()
	{
		return this->percent5;
	}
	void calculation()
	{
		cout << "The numbers in first paper are " << get_paper1() << endl;
		cout << "The Percentage for first paper is " << get_percent1() << "%" << endl;
		cout << "The numbers in second paper are " << get_paper2() << endl;
		cout << "The Percentage for second paper is " << get_percent2() << "%" << endl;
		cout << "The numbers in third paper are " << get_paper3() << endl;
		cout << "The Percentage for third paper is " << get_percent3() << "%" << endl;
		cout << "The numbers in fourth paper are " << get_paper4() << endl;
		cout << "The Percentage for fourth paper is " << get_percent4() << "%" << endl;
		cout << "The numbers in fifth paper are " << get_paper5() << endl;
		cout << "The Percentage for fifth paper is " << get_percent5() << "%" << endl;
		cout << "The Average Percentage for all the papers is " << get_average() << "%" << endl;
	}
};
int main()
{
	Evolution salman; 
	float num1, num2, num3, num4, num5, percent, average;
	double  perc1, perc2, perc3, perc4, perc5;
	cout << "Enter the number of Papers from 0-100." << endl;
	cout << "Paper 1: " << endl;
	cin >> num1;
	if (num1  < 0 || num1 > 100)
	{
		cout << "Invalid Input !" << endl;
		return 0;
	}
	cout << "Paper 2: " << endl;
	cin >> num2;
	if (num2 < 0 || num2 > 100)
	{
		cout << "Invalid Input !" << endl;
		return 0;
	}
	cout << "Paper 3: " << endl;
	cin >> num3;
	if (num3 < 0 || num3 > 100)
	{
		cout << "Invalid Input !" << endl;
		return 0;
	}
	cout << "Paper 4: " << endl;
	cin >> num4;
	if (num4 < 0 || num4 > 100)
	{
		cout << "Invalid Input !" << endl;
		return 0;
	}
	cout << "Paper 5: " << endl;
	cin >> num5;
	if (num5 < 0 || num5 > 100)
	{
		cout << "Invalid Input !" << endl;
		return 0;
	}
	average = (num1 + num2 + num3 + num4 + num5) / 5;
	perc1 = (num1 / 100) * 150;
	perc2 = (num2 / 100) * 100;
	perc3 = (num3 / 100) * 100;
	perc4 = (num4 / 100) * 100;
	perc5 = (num5 / 100) * 100;
	salman.set_percent1(perc1);
	salman.set_percent2(perc2);
	salman.set_percent3(perc3);
	salman.set_percent4(perc4);
	salman.set_percent5(perc5);
	salman.set_paper1(num1);
	salman.set_paper2(num2);
	salman.set_paper3(num3);
	salman.set_paper4(num4);
	salman.set_paper5(num5);
	salman.set_average(average);
	salman.calculation();
	if (average > 90 && average < 100)
	{
		cout << "Your Grade is 'A'" << endl;
	}
	else if (average > 80 && average < 89)
	{
		cout << "Your Grade is 'B'" << endl;
	}
	if (average > 70 && average < 79)
	{
		cout << "Your Grade is 'C'" << endl;
	}
	else if (average > 60 && average < 69)
	{
		cout << "Your Grade is 'D'" << endl;
	}
	if (average > 50 && average < 59)
	{
		cout << "Your Grade is 'D'" << endl;
	}
	else if(average < 49)
	{
		cout << "You're Fail" << endl;
	}
	system("pause>0");
	return 0;
}