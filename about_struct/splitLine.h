#pragma once
#include <iostream>
namespace split_line {
	enum line
	{
		dotedLine,//����
		straightLine,//ֱ��
		wavyLines//������
	};
	//��һ���ߣ�24����λ
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