#include<stdafx.h>
#include<help.h>

#include<conio.h>

using namespace std;

int main() {



	locale loc("chs"); // ���塰�������á�Ϊ���ķ�ʽ
	wcout.imbue(loc); // ���������ַ����뷽ʽ
	

	/*���û����Ŀ���̨��С�����*/

	SetConsoleTitle("�ı��༭��");
	system("mode con cols=190 lines=50");

	COORD size = { 190, 50 };
	SET_BUFFERSIZE(size);
	SMALL_RECT rc = { 0,0, 190 - 1, 50 - 1 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rc);
	/*end*/

	/*����̨��ҳ����*/
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
	/*����̨��ҳ����*/
	SET_COLOR(FOREGROUND_GREEN);
	COORD j = {55, 18};
	SET_POSITION(j);
	cout << "��ӭ��ʹ����wsh��д���ı��༭��";
	j.X += 4;
	j.Y = 20;
	SET_POSITION(j);
	cout << "����\\help�ܵõ�������Ϣ";
	/*end*/

	/*����/help��*/
	j.X = 0;
	j.Y = 41;
	SET_POSITION(j);
	Console_Help help;
	while (1) {
		SET_COLOR(FOREGROUND_GREEN);
		cout << "��������Ҫ������ָ��" << endl;
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