// File: Driver.cpp
// 
// Simple test of insertion

#include <iostream>
using namespace std;

#include "CTree.h"

int main() {

	CTree T;

	T.insert(70);
	T.inorder(); cout << endl;

	T.insert(30);
	T.inorder(); cout << endl;

	T.insert(110);

	T.inorder(); cout << endl;

	cout << "\n\n***** Insert 40 *****\n";
	T.insert(40);
	T.inorder(); cout << endl;

	cout << "\n\n***** Insert 20 *****\n";
	T.insert(20);
	T.inorder(); cout << endl;

	cout << "\n\n***** Insert 41 *****\n";
	T.insert(41);
	T.inorder(); cout << endl;

	cout << "\n\n***** Insert 31 *****\n";
	T.insert(31);
	T.inorder(); cout << endl;

	cout << "\n\n***** Insert 32 *****\n";
	T.insert(32);
	T.inorder(); cout << endl;

	cout << "\n\n***** Insert 33 *****\n";
	T.insert(33);
	T.inorder(); cout << endl;

	cout << "\n\n***** Insert 19 *****\n";
	T.insert(19);
	T.inorder(); cout << endl;

	cout << "\n\n***** Insert 34 *****\n";
	T.insert(34);
	T.inorder(); cout << endl;

	cout << "\n\n***** Insert 15 *****\n";
	T.insert(15);
	T.inorder(); cout << endl;

	cout << "\n\n***** Insert 14 *****\n";
	T.insert(14);
	T.inorder(); cout << endl;

	CTree T2;

	T2.insert(14);

	T2.insert(7);
	T2.insert(25);

	T2.insert(3); T2.insert(32);
	T2.insert(9); T2.insert(18);

	T2.insert(1); T2.insert(44);
	T2.insert(12); T2.insert(15);
	T2.insert(4); T2.insert(29);
	T2.insert(10); T2.insert(21);

	T2.inorder(); cout << endl;

	cout << "removing ..." << endl;
	//   T.dump() ;

	int n;

	n = 44; cout << "removing " << n << endl; T2.remove(n); T2.inorder(); cout << endl;
	n = 32; cout << "removing " << n << endl; T2.remove(n); T2.inorder(); cout << endl;
	n = 29; cout << "removing " << n << endl; T2.remove(n); T2.inorder(); cout << endl;
	n = 21; cout << "removing " << n << endl; T2.remove(n); T2.inorder(); cout << endl;
	n = 18; cout << "removing " << n << endl; T2.remove(n); T2.inorder(); cout << endl;
	
	CTree T3;

	T3.insert(14);

	T3.insert(7);
	T3.insert(25);

	T3.insert(3); T3.insert(32);
	T3.insert(9); T3.insert(18);

	// Inserting duplicates

	T3.insert(3); T3.insert(32);
	T3.insert(9); T3.insert(18);

	T3.insert(1); T3.insert(44);
	T3.insert(12); T3.insert(15);

	T3.inorder(); cout << endl;

	cout << "removing ..." << endl;
	int answer;
	//   T.dump() ;

	int m;

	m = 14; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;
	m = 12; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;
	m = 7; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;
	m = 25; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;
	m = 3; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;
	m = 29; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;
	m = 32; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;
	m = 15; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;


	// Removing items that do not exist
	cout << endl;
	m = 19; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;
	m = 101; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;
	m = -32; cout << "removing " << m << endl; T3.remove(m); T3.inorder(); cout << endl;
	cout << endl;

	CTree T4;

	T4.insert(14);

	T4.insert(7);
	T4.insert(3); T4.insert(1); T4.insert(4);
	T4.insert(10); T4.insert(9); T4.insert(12);

	T4.insert(25);
	T4.insert(18); T4.insert(15); T4.insert(21);
	T4.insert(32); T4.insert(29); T4.insert(44);

	//   T.dump() ;
	T4.inorder(); cout << endl;

	int x;
	//int answer;


	x = 3;
	cout << "Find " << x << endl;
	if (T4.find(x)) {
		cout << "found = " << x << endl;
	}
	else {
		cout << "did not find = " << x << endl;
	}
	cout << endl;


	x = 4;
	cout << "Find " << x << endl;
	if (T4.find(x)) {
		cout << "found = " << x << endl;
	}
	else {
		cout << "did not find = " << x << endl;
	}
	cout << endl;


	x = 29;
	cout << "Find " << x << endl;
	if (T4.find(x)) {
		cout << "found = " << x << endl;
	}
	else {
		cout << "did not find = " << x << endl;
	}
	cout << endl;

	x = 301;
	cout << "Find " << x << endl;
	if (T4.find(x)) {
		cout << "found = " << x << endl;
	}
	else {
		cout << "did not find = " << x << endl;
	}
	cout << endl;

	// Checking remove...

	x = 21;
	cout << "Remove " << x << endl;
	if (T4.remove(x)) {
		cout << x << " removed\n";
	}
	else {
		cout << x << " not found\n";
	}
	T4.inorder(); cout << endl;

	x = 18;
	cout << "Remove " << x << endl;
	if (T4.remove(x)) {
		cout << x << " removed\n";
	}
	else {
		cout << x << " not found\n";
	}
	T4.inorder(); cout << endl;

	x = 7;
	cout << "Remove " << x << endl;
	if (T4.remove(x)) {
		cout << x << " removed\n";
	}
	else {
		cout << x << " not found\n";
	}
	T4.inorder(); cout << endl;

	x = 13;
	cout << "Remove " << x << endl;
	if (T4.remove(x)) {
		cout << x << " removed\n";
	}
	else {
		cout << x << " not found\n";
	}
	T4.inorder(); cout << endl;

	CTree T5;

	T5.insert(14);

	T5.insert(7);
	T5.insert(25);

	T5.insert(3); T5.insert(32);
	T5.insert(9); T5.insert(18);

	T5.insert(1); T5.insert(44);
	T5.insert(12); T5.insert(15);
	T5.insert(4); T5.insert(29);
	T5.insert(10); T5.insert(21);

	cout << "Original T1:         ";
	T5.inorder(); cout << endl;

	// Use copy constructor
	CTree *Tptr = new CTree(T5);

	cout << "Copied T1:           ";
	Tptr->inorder(); cout << endl;

	CTree T6;

	T6.insert(50);
	T6.insert(25); T6.insert(75);
	// T2.inorder() ; cout << endl ;

	T6 = *Tptr;
	cout << "Second copy:         ";
	T6.inorder(); cout << endl;

	cout << "Delete first copy...\n";
	delete Tptr;

	cout << "Recheck original:    ";
	T5.inorder(); cout << endl;
	cout << "Recheck second copy: ";
	T6.inorder(); cout << endl;

	CTree T7;

	T7.insert(70);
	T7.insert(30);
	T7.insert(110);
	T7.insert(40);
	T7.insert(20);
	T7.insert(41);
	T7.insert(31);
	T7.insert(32);
	T7.insert(33);
	T7.insert(19);
	T7.insert(34);
	T7.insert(15);
	T7.insert(14);

	T7.inorder(); cout << endl;

	int key = 9999;
	bool ans;
	const char *str;

	ans = T7.locate(str = "", key = -1);
	cout << str << ": " << ans << " " << key << endl;

	ans = T7.locate(str = "LL", key = -1);
	cout << str << ": " << ans << " " << key << endl;

	ans = T7.locate(str = "LLR", key = -1);
	cout << str << ": " << ans << " " << key << endl;

	ans = T7.locate(str = "RLLR", key = -1);
	cout << str << ": " << ans << " " << key << endl;

}