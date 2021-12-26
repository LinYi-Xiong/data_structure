/*
	用于研究数据结构方面的知识
*/
#include <iostream>
#include "list.h"
#include "splitLine.h"

using namespace std;
using namespace split_line;

/*------------------------------------*/
//链表的使用
void in(myLinkList::List* list);

void runList() {
	using std::cout;
	using std::cin;
	myLinkList::List* lest = new myLinkList::List();
	char po;
	do {
		drawLine(straightLine);

		cout << "使用说明：" << endl
			<< "a`指定位置插入数据" << endl
			<< "b`是否为空" << endl
			<< "c`修改指定位置数据" << endl
			<< "d`删除指定位置数据" << endl
			<< "e`退出" << endl
			<< "f`搜索数据所在位置" << endl
			<< "q`存入的数据数量" << endl
			<< "i`输入数据：第一步输入需要添加的数据数量，第二步输入需要添加的数据使用空格隔开" << endl
			<< "s`展示已存入的数据" << endl
			;

		cin >> po;
		drawLine(wavyLines);

		switch (po)
		{
		case 'a':
			int a_where, a_type;
			cout << "输入位置" << endl;
			cin >> a_where;
			cout << "输入数据" << endl;
			cin >> a_type;
			lest->insert(a_where, a_type);
			break;
		case 'b':
			cout << "当前链表is空？ " << lest->isEmpty() << endl;
			break;
		case 'c':
			int c_where, c_type;
			cout << "输入位置" << endl;
			cin >> c_where;
			cout << "输入数据" << endl;
			cin >> c_type;
			lest->change(c_where, c_type);
			break;
		case 'd':
			int d_where;
			cout << "输入需要删除的位置" << endl;
			cin >> d_where;
			lest->deleteType(d_where);
			break;
		case 'f':
			int f_type;
			cout << "输入查找的数据" << endl;
			cin >> f_type;
			cout << "数据所在的位置： " << lest->findType(f_type) << endl;
			break;
		case 'q':
			cout << "当前链表容量： " << lest->quantity() << endl;
			break;
		case 'i':
			cout << "0为后插，1为前插" << endl;
			int i_point;
			cin >> i_point;
			lest->init(i_point);

			in(lest);
			break;
		case 's':
			lest->showTypes();
			break;
		default:break;
		}//#switch
	} while (po != 'e');

	delete lest;
}//#runList


//runList::in
void in(myLinkList::List* list) {
	int n;
	int type;
	cout << "in" << endl;
	cin >> n;
	//cin.clear();
	cout << "数据" << endl;
	for (int i = 0; i < n; i++) {
		cin >> type;
		list->add(type);
	}

	cout << "数据输入完成" << endl;
}//#runList::in
/*---------------------------------------*/



//调度中心
int main() {
	int name = -1;
	do {
		drawLine(dotedLine);
		cout << "请输入想要运行的模块" << endl
			<< "1->链表" << endl
			<< "0->退出" << endl;

		cin >> name;
		cin.clear();
		switch (name)
		{
		case 0:cout << "bye" << endl; break;
		case 1: runList(); break;
		default:break;

		}
	} while (name != 0);
}