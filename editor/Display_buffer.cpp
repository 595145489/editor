#include<stdafx.h>
#include<Display_buffer.h>

#define Xmin 170
#define Ymin 47

Display_buffer::Display_buffer() {
	this->Y_length = Ymin;
	if(!this->X_data.empty())
		this->X_data.clear();
};

int Display_buffer::Y_max() {
	return Y_length;
};

int Display_buffer::X_max() {
	if (X_data.empty())
		return 0;
	return *(X_data.begin());
};

//flage是为了写入是增加还是删除某个数据
//默认是添加数据,即flage = 1;
void Display_buffer::X_data_change(int X_change_number,bool flage = 1 ) {
	try
	{
		if (flage) {
			this->X_data.insert(X_change_number);
		}
		else {
			this->X_data.erase(this->X_data.find(X_change_number));
		}
	}
	catch (const std::exception&)
	{

	}
	return;
};

void Display_buffer::Y_length_change(int Y_length_number) {
	this->Y_length = Y_length_number;
	return;
};


Display_Controller::Display_Controller() {
	this->display = new Display_buffer;
};
Display_Controller::~Display_Controller() {
	delete this->display;
};

//此处传入的是总的Y长度
void Display_Controller::Y_up(int Y_length) {

	//屏幕显示缓冲区在Y 轴不低于50
	if ( Y_length < Ymin)
		return;
	this->display->Y_length_change(Y_length);
	int X = Xmin;
	 X = X >= this->display->X_max() ? Xmin : this->display->X_max();
		
	COORD size = { X+20, Y_length+3 };
	SET_BUFFERSIZE(size);
	return;
};
void Display_Controller::X_up(int X_length, bool flage = 1) {


	if (X_length < Xmin) {
		if (!this->display->X_max()) {
			COORD size = { Xmin, this->display->Y_max() + 3 };
			SET_BUFFERSIZE(size);
		}	
		return;
	}
		


	if (X_length > this->display->X_max()) {
		COORD size = { X_length+20, this->display->Y_max() + 3 };
		SET_BUFFERSIZE(size);
	}

	if (flage) 
		this->display->X_data_change(X_length);
	else
		this->display->X_data_change(X_length, 0);

	
	
	return;
};

