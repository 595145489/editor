#include<stdafx.h>
#include<file_change.h>

using namespace std;


void File_Save::Save_ctrl_s() {

	try
	{
		this->file->seekp(0, ios::beg);
		this->file->seekg(0, ios::beg);
		for (dlsptd_lt a = this->operating_data->table->begin(); \
			a != this->operating_data->table->end(); a++) {
			for (lstd_lt b = (*a).splsta_data->begin(); b != (*a).splsta_data->end(); b++) {
				*(this->file) << b->text;
			}
#if IN_WHERE==IN_WIN 
			* (this->file) << "\r\n";
#elif IN_WHERE==IN_LINUX
			* (this->file) << "\\n";
#endif 
		}
	}
	catch (...)
	{
		
	}
	



	return;
};


void File_Save_Conself::Run_ctrl_s() {

	this->Save_ctrl_s();
	return;
	
};

void File_Save_Conself::Run_esc() {



#if IN_WHERE == IN_WIN
	if (MessageBox(NULL, TEXT("你选择退出,是否保存"), TEXT("提示"), MB_ICONINFORMATION | MB_YESNO) == IDYES)
	{
		this->Save_ctrl_s();
	}
	
#elif IN_WHERE==IN_LINUX

#endif
	return;
}
