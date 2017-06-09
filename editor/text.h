#pragma once
#include<operating.h>
#include<file_change.h>
#include<display_buffer.h>
class Text_Change {
protected:
	typedef operating_data::data this_data;

	virtual void Pretreatment(std::string) = 0;
	virtual void Run(file_type*,std::string) = 0;
	virtual ~Text_Change();
	static COORD * const table_xy;

};

class Text_Change_Console :public Text_Change{
public:
	Text_Change_Console::Text_Change_Console();
	void Pretreatment(std::string);
	void Run(file_type*,std::string);
	void Change(operating*);
	~Text_Change_Console();
private:
	file_type* file_name;
	this_data* Console_table;
	dlsptd table;
	Display_Controller* buffer_dislay;
	Explanation* grammar;
	short Serial_number_flag; //0关闭序号显示 1打开序号显示 2重开序号显示

	void XBackspace_buffer();
	void XEnter_buffer();
	void XGetchar_buffer();
	void Serial_number_ONOFF(bool);
	void Set_grammar();
};

