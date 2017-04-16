// 002Eceptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int _tmain(int argc, _TCHAR* argv[])
{
	using std::cout;
	using std::cin;
	using std::endl;////cmnt

	double vals1[12] = 
	{
	1220, 1100, 1122, 2212, 1232, 2334,
	2884, 2393, 3302, 2922, 3002, 3544
	};

	double vals2[12] = 
	{
		12,11,22,21,32,34,
		28,29,33,29,32,25
	};

	Sales sales1(2011,vals1,12);
	LabeledSales sales2("Blgstr",2012,vals2,12);

	cout << "======== :\n";
	try{
		int i;
		cout << "Rok = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{
			cout << sales1[1];
			if(i % 6 == 5)
				cout << endl;
		}
		cout << "Finish processing try 1\n";
	}
	catch(LabeledSales::nbad_index & bad)
	{
		cout << bad.what();
		cout << "Firmware: " << bad.label_val() << endl;
		cout << "Wrong indeks: " << bad.bi_val() << endl;
	
	}
	catch(Sales::bad_index & bad)
	{
		cout << bad.what();
		cout << "Wrong index: " << bad.bi_val() << endl;
	}
	cout << "\nNext Steps\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "end of second try \n";
	}
	catch(LabeledSales::nbad_index & bad)
	{
		cout << bad.what();
		cout << "Frm: " << bad.label_val() << endl;
		cout << "Wrong index: " << bad.bi_val() << endl;
	}
	catch(Sales::bad_index & bad)
	{
		cout << bad.what();
		cout << "Niepoprawny indeks: " << bad.bi_val() << endl;
	}

	cout << "finished\n";
	return 0;
}

