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
		cout << "请输入正确的指令" << endl;
		return true;
	}
		
};


void Console_Help::Cin_help() {
	cout << "你有以下命令选择" << endl;
	cout << "\\nfile    此命令为新建一个新的文件" << endl;
	cout << "\\ofile    此命令为打开一个现有的文件" << endl;
	cout << "\\out 退出本程序" << endl;
	return;
};
void Console_Help::Cin_new_file() {
	try
	{
		string add_file,file_name;
		cout << "请输入你要保存的文件地址(按回车完成输入)" << endl;
		cout << "格式:: c:\\file1\\file2  输入\".\"直接在当前路径下创建" << endl;
		SET_COLOR(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cin >> add_file;
		SET_COLOR(FOREGROUND_RED);
		cout << "请输入文件名" << endl;
		SET_COLOR(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		add_file += "\\";
		cin >> file_name;

		file_type file1;
		file1.open(add_file + file_name, ios::out | ios::_Noreplace);

		if (!file1) {
#if IN_WHERE == IN_WIN
			if (MessageBox(NULL, TEXT("文件存在,是否覆盖"), TEXT("提示"),MB_ICONINFORMATION | MB_YESNO) == IDYES)
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
		MessageBox(NULL, TEXT("文件创建成功，请写入内容,按ESC键可结束写入"), TEXT("提示"), MB_OK);
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
		cout << "请输入你要打开的文件地址(按回车完成输入)" << endl;
		cout << "格式:: c:\\file1\\file2\\1.txt  输入\".\\1.txt\"直接当前路径下寻找" << endl;
		SET_COLOR(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cin >> add_file;

		file_type file1(add_file, ios::in | ios::_Nocreate | ios::out);
		
		if (!file1) {
#if IN_WHERE == IN_WIN
			MessageBox(NULL, TEXT("文件不存在"), TEXT("提示"), MB_ICONINFORMATION);
#endif
			file1.close();
			return;
			
		}
#if IN_WHERE == IN_WIN
		MessageBox(NULL, TEXT("文件打开成功，请写入内容,按ESC键可结束写入"), TEXT("提示"), MB_OK);
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