#pragma once

//ֻ�����ڲ�ά������˽�б���,��װ�ε���Y_max��X_max����
class Display_buffer {
public:
	Display_buffer::Display_buffer();
	int Y_max();
	int X_max();
	void X_data_change(int,bool);
	void Y_length_change(int);
private:
	int Y_length;
	setit X_data;
};

class Display_Controller {
public:
	Display_Controller::Display_Controller();
	Display_Controller::~Display_Controller();
	void Y_up(int);
	void X_up(int, bool);
private:
	Display_buffer* display;
};