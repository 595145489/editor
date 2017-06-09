#include<stdafx.h>
#include<help.h>
#include<text.h>
using namespace std;
bool Help::Run(string std) {

	
	if (std == "\\help") {

		this->Cin_help();
		return true;
	}
	else if (std == "\\out") {
		return false;
	}
	else if (std == "\\nfile") {
		this->Cin_new_file();
		return true;
	}
	else if (std == "\\ofile") {
		this->Cin_open_file();
	}
	else {
		cout << "��������ȷ��ָ��" << endl;
		return true;
	}
		
};


void Console_Help::Cin_help() {
	cout << "������������ѡ��" << endl;
	cout << "\\nfile    ������Ϊ�½�һ���µ��ļ�" << endl;
	cout << "\\ofile    ������Ϊ��һ�����е��ļ�" << endl;
	cout << "\\out �˳�������" << endl;
	return;
};
void Console_Help::Cin_new_file() {
	try
	{
		string add_file,file_name;
		cout << "��������Ҫ������ļ���ַ(���س��������)" << endl;
		cout << "��ʽ:: c:\\file1\\file2  ����\".\"ֱ���ڵ�ǰ·���´���" << endl;
		SET_COLOR(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cin >> add_file;
		SET_COLOR(FOREGROUND_RED);
		cout << "�������ļ���" << endl;
		SET_COLOR(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		add_file += "\\";
		cin >> file_name;

		file_type file1;
		file1.open(add_file + file_name, ios::out | ios::_Noreplace);

		if (!file1) {
#if IN_WHERE == IN_WIN
			if (MessageBox(NULL, TEXT("�ļ�����,�Ƿ񸲸�"), TEXT("��ʾ"),MB_ICONINFORMATION | MB_YESNO) == IDYES)
			{
				
				file1.close();
				file1.open(add_file + file_name, ios::out);
				

			} 
#endif
			else {
				file1.close();
				return;
			}
		}	
		SET_CLS;
#if IN_WHERE == IN_WIN
		MessageBox(NULL, TEXT("�ļ������ɹ�����д������,��ESC���ɽ���д��"), TEXT("��ʾ"), MB_OK);
#endif

		Text_Change_Console text_change;
		file1.imbue(locale("chs"));
		text_change.Run(&file1,"new_file");
		file1.close();

	}
	catch (...)
	{
	}
	return;
}


void Console_Help::Cin_open_file() {
	try
	{
		string add_file;
		cout << "��������Ҫ�򿪵��ļ���ַ(���س��������)" << endl;
		cout << "��ʽ:: c:\\file1\\file2\\1.txt  ����\".\\1.txt\"ֱ�ӵ�ǰ·����Ѱ��" << endl;
		SET_COLOR(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cin >> add_file;

		file_type file1(add_file, ios::in | ios::_Nocreate | ios::out);
		
		if (!file1) {
#if IN_WHERE == IN_WIN
			MessageBox(NULL, TEXT("�ļ�������"), TEXT("��ʾ"), MB_ICONINFORMATION);
#endif
			file1.close();
			return;
			
		}
#if IN_WHERE == IN_WIN
		MessageBox(NULL, TEXT("�ļ��򿪳ɹ�����д������,��ESC���ɽ���д��"), TEXT("��ʾ"), MB_OK);
#endif
		
		SET_CLS;
		Text_Change_Console text_change;
		file1.imbue(locale("chs"));
		text_change.Run(&file1,"open_file");
		file1.close();
		
	}
	catch (...)
	{
	}
	return;

};