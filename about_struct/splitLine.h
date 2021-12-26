#pragma once
#include <iostream>
namespace split_line {
	enum line
	{
		dotedLine,//虚线
		straightLine,//直线
		wavyLines//波浪线
	};
	//画一条线，24个单位
	void drawLine(int line_name) {
		using std::cout;
		using std::endl;

		switch (line_name)
		{
		case dotedLine:
			cout << "........................" << endl;
			break;
		case straightLine:
			cout << "________________________" << endl;
			break;
		case wavyLines:
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		default:
			break;
		}
	}
}