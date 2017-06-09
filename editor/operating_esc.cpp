#include<stdafx.h>
#include<operating.h>

operating_esc::operating_esc(this_data* somedata) :operating(somedata) {};

void operating_esc::Cursor_handl() {

	return;
};
int operating_esc::Data_handl() {
	return 0;
};

void operating_esc::Run() {
	Cursor_handl();

	return;
};

