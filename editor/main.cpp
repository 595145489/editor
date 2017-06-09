#include<stdafx.h>
#include<help.h>

#include<conio.h>

using namespace std;

int main() {



	locale loc("chs"); // 定义“区域设置”为中文方式
	wcout.imbue(loc); // 载入中文字符输入方式
	

	/*设置基本的控制台大小标题等*/

	SetConsoleTitle("文本编辑器");
	system("mode con cols=190 lines=50");

	COORD size = { 190, 50 };
	SET_BUFFERSIZE(size);
	SMALL_RECT rc = { 0,0, 190 - 1, 50 - 1 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rc);
	/*end*/

	/*控制台首页绘制*/
	SET_COLOR(FOREGROUND_BLUE);
	for (short a = 0; a <= 40; a++) {
		for (short b = 0; b <= 150; b++) {
	
			if ((b == 0 || b == 150) && (a == 0 || a == 40))
				cout << "*";
			else if (a == 0 || a == 40)
				cout << "-";
			else if (b == 0 || b == 150)
				cout << "|";
			else
				cout << " ";
		}
		cout << endl;
	}
	/*控制台首页绘制*/
	SET_COLOR(FOREGROUND_GREEN);
	COORD j = {55, 18};
	SET_POSITION(j);
	cout << "欢迎您使用由wsh编写的文本编辑器";
	j.X += 4;
	j.Y = 20;
	SET_POSITION(j);
	cout << "输入\\help能得到帮助信息";
	/*end*/

	/*输入/help等*/
	j.X = 0;
	j.Y = 41;
	SET_POSITION(j);
	Console_Help help;
	while (1) {
		SET_COLOR(FOREGROUND_GREEN);
		cout << "请输入你要操作的指令" << endl;
		SET_COLOR(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		string str;
		cin >> str;
		SET_COLOR(FOREGROUND_RED);	
		bool is_close  = help.Run(str);
		if (!is_close)
			break;
	}
	

	return 0;
}