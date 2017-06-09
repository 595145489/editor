#include<stdafx.h>
#include<text.h>

#if IN_WHERE == IN_WIN
#include<conio.h>
#endif

using namespace  std;

COORD * const Text_Change::table_xy = (COORD*)malloc(sizeof(COORD));

Text_Change::~Text_Change() {
	free(this->table_xy);
};

void Text_Change_Console::Pretreatment(string oder) {


	this->Serial_number_flag = 1; //需移动到配置文件

	this->table_xy->X = 0 + OFFSET;
	this->table_xy->Y = 0;
	this->table.clear();

	this->Console_table = (this_data*)malloc(sizeof(this_data));

	this->Console_table->position = table_xy;
	this->Console_table->table = &table;

	this->Serial_number_ONOFF(1);

	splstd first_lstd(new lstd());
	this->table.push_back({first_lstd,0});
	
	this->Set_grammar(); //设置语法解释引擎

	SET_POSITION(*this->Console_table->position);

	if (oder=="new_file") {
		return;
	}
	else if (oder == "open_file") {
		wstring s;
		int ch;
		this->Console_table->text = &ch;

		while (*(this->file_name) >> s) {
			for (int a = 0;a<s.size();a++) {
				ch = (int)s[a];
				this->Change(operating::transfer<operating_getchar>(this->Console_table));
			}
			ch = Enter;
			this->Serial_number_ONOFF(1);
			this->Change(operating::transfer<operating_enter>(this->Console_table));			
		}
	}

	return;
};

void Text_Change_Console::Change(operating* x) {

	x->Run();
	return;
};

void Text_Change_Console::Run(file_type* file_name,string oder) {

	

	this->file_name = file_name;

	this->Pretreatment(oder);

	this->file_name->clear();

	File_Save_Conself file(this->file_name, this->Console_table);
	
	bool out = 1; //退出程序使用,为0则退出
	int x;
	this->Console_table->text = &x;

	while (1) {

	#if IN_WHERE==IN_WIN
		x = _getwch();
	#elif IN_WHERE==IN_LINUX
		x = getch();
	#endif 
		switch (x)
		{
		case CTRL_KEY: 
			switch (_getwch())
			{
				//方向键
			case CTRL_LEFT:
				this->Change(operating::transfer<operating_left>(this->Console_table));
				break;
			case CTRL_RIGHT:
				this->Change(operating::transfer<operating_right>(this->Console_table));
				break;
			case CTRL_DOWN:
				this->Change(operating::transfer<operating_down>(this->Console_table));
				break;
			case CTRL_UP:
				this->Change(operating::transfer<operating_top>(this->Console_table));
				break;
			}
			break;
		case Enter://回车
			//横坐标有BUG ,等待修改
			this->Serial_number_ONOFF(1);
			this->XEnter_buffer();
			this->Change(operating::transfer<operating_enter>(this->Console_table));
			break;
		case Backspace: //退格
			this->Serial_number_ONOFF(0);
			this->XBackspace_buffer(); //设定屏幕显示缓冲器
			this->Change(operating::transfer<operating_backspace>(this->Console_table));	
			this->buffer_dislay->X_up((*(this->Console_table->table))[this->Console_table->position->Y].length , 1);
			break;
		case ESC:
			out = 0;
			file.Run_esc();
			break;
		case CTRL_S: // ctrl+s 保存文档
			file.Run_ctrl_s();
			break;
		default:					
			this->Change(operating::transfer<operating_getchar>(this->Console_table));
			this->XGetchar_buffer();
			break;
		}
		if (!out)
			break;
	}

	SET_CLS;
	return;

};




void Text_Change_Console::Serial_number_ONOFF(bool change_flag = 1) {

	if (Serial_number_flag == 0)
		return;
	SET_COLOR( FOREGROUND_GREEN);
	
	if (Serial_number_flag == 2) { //重新打开序号显示, 需重头重写序号
		for (int num = 0; num <= this->Console_table->table->size(); num++) {
			COORD Serial = { OFFSET_NUM, num };
			SET_POSITION(Serial);
			wcout << num;
		}
		this->Serial_number_flag = 1; 
	}
	else if (Serial_number_flag == 1) {
		if (!change_flag) {
			if (this->Console_table->position->X != 0 + OFFSET || this->Console_table->position->Y == 0) {
				SET_COLOR(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				return;
			}
			COORD Serial = { OFFSET_NUM, this->Console_table->table->size() - 1 };
			SET_POSITION(Serial);
			wcout << "    ";

		}
		else {
			COORD Serial = { OFFSET_NUM, this->Console_table->table->size() };
			SET_POSITION(Serial);
			cout << this->Console_table->table->size()+1;
		}	
	}
	

	SET_COLOR(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}


void Text_Change_Console::XGetchar_buffer() {
	this->buffer_dislay->X_up((*(this->Console_table->table))[this->Console_table->position->Y].length, 1);
	this->buffer_dislay->X_up((*(this->Console_table->table))[this->Console_table->position->Y].length - this->Console_table->coding_flags, 0);
	return;
};
void Text_Change_Console::XEnter_buffer() {
	if ((this->Console_table->position->X - OFFSET)&& this->Console_table->position->X - OFFSET !=\
		(*(this->Console_table->table))[this->Console_table->position->Y].length) {
		this->buffer_dislay->X_up((*(this->Console_table->table))[this->Console_table->position->Y].length, 0);
		this->buffer_dislay->X_up((*(this->Console_table->table))[this->Console_table->position->Y].length - this->Console_table->position->X - OFFSET, 1);
		this->buffer_dislay->X_up(this->Console_table->position->X - OFFSET, 1);
	}

	this->buffer_dislay->Y_up(this->Console_table->table->size());

	return;
}
void Text_Change_Console::XBackspace_buffer() {

	if (!(this->Console_table->position->X - OFFSET) && this->Console_table->position->Y) {
		this->buffer_dislay->X_up((*(this->Console_table->table))[this->Console_table->position->Y].length,0);
		this->buffer_dislay->X_up((*(this->Console_table->table))[this->Console_table->position->Y-1].length, 0);
	}
	else {
		this->buffer_dislay->X_up((*(this->Console_table->table))[this->Console_table->position->Y].length, 0);
	}

	this->buffer_dislay->Y_up(this->Console_table->table->size());

	return;
};
Text_Change_Console::Text_Change_Console() {
	this->buffer_dislay = new Display_Controller;
};
Text_Change_Console::~Text_Change_Console() {

	free(this->Console_table);
	delete this->buffer_dislay;
	delete this->grammar;
};


void Text_Change_Console::Set_grammar() {
	grammar = new Explanation;

	operating::transfer<operating_getchar>(this->Console_table)->Get_grammar(grammar);
};