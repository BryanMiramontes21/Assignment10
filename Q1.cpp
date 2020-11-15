#include <iostream>
#include <algorithm>
using namespace std;

class rational
{
public:
	
	int a1 = 0, a2 = 0, b1 = 0, b2 = 0, AB1 = 0 , AB2 = 0;
	string userinput = "+";

	rational(int r1, int r2)
	{
		r1 = a1;
		r2 = a2;
		r1 = b1;
		r2 = b2;
	}
	 
	void Rational1()
	{
		cout << "Input Numerator : "; cin >> a1;
		cout << "Input Denumerator : "; cin >> a2;
		
		if (a1 < 0)
		{
			a1 = -a1;
		}
		if (a2 < 0)
		{
			a2 = -a2;
		}

		validate1(a1 , a2);
	}

	void Rational2()
	{
		cout << "Input Numerator : "; cin >> b1;
		cout << "Input Denumerator : "; cin >> b2;
		
		if (b1 < 0)
		{
			b1 = -b1;
		}
		if (b2 < 0)
		{
			b2 = -b2;
		}

		validate2(b1, b2);
	}
	
	int gcd(int a, int b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	void lowest(int& den, int& num)
	{
		 
		int common_factor = gcd(AB1, AB2);
 
		AB2 = AB2 / common_factor;
		AB1 = AB1 / common_factor;	
	}

	int lcm(int a, int b)
	{
		return (a * b) / gcd(a, b);
	}

	void Rationaloperations()
	{	
		
			cout << "Would you like to Add, subtract, multiply or divide the rationals : (Use the symbols +, -, *, / or No to end) "; cin >> userinput;
			
			if (userinput == "+")
			{

				AB2 = lcm(a2, b2);
				AB1 = (a1) * (AB2 / a2) + (b1) * (AB2 / b2);
				lowest(AB1, AB2);
				userinput = "Addition ";
			}

			if (userinput == "-")
			{
				AB2 = lcm(a2, b2);
				AB1 = (a1) * (AB2 / a2) - (b1) * (AB2 / b2);
				lowest(AB1, AB2);
				userinput = "Subtraction ";
			}

			if (userinput == "*")
			{
				AB2 = a2 * b2;
				AB1 = a1 * b1 ;
				lowest(AB1, AB2);
				userinput = "Multiplication ";
			}

			if (userinput == "/")
			{
				AB2 = a2 / b2;
				AB1 = a1 / b1;
				lowest(AB1, AB2);
				userinput = "Division ";
			}
			
	}

	void validate1(int& a1, int& a2)
	{
		while (a1 == 0 || a2 == 0)
		{
			cout << "Rational may not have a 0 Numerator or Denumerator" << endl;
			cout << "Input Numerator : "; cin >> a1;
			cout << "Input Denumerator : "; cin >> a2;
		}
	}

	void validate2(int& b1, int& b2)
	{
		while (b1 == 0 || b2 == 0)
		{
			cout << "Rational may not have a 0 Numerator or Denumerator" << endl;
			cout << "Input Numerator : "; cin >> b1;
			cout << "Input Denumerator : "; cin >> b2;
		}
	}

	void print()
	{
		cout << endl << "Your first set of Rationals was " << a1 << "/" << a2 << endl;
		cout << endl << "Your second set of Rationals was " << b1 << "/" << b2 << endl;
		cout<<"The " << userinput << "of both rationals equals to : " << AB1 << "/" << AB2 << endl;
	}
};

int main()
{
	int num = 0, denum = 0;

	rational R(num, denum);
	R.Rational1();
	R.Rational2();
	R.Rationaloperations();
	R.print();
	
}