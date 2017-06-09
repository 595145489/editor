#include<stdafx.h>
#include<operating.h>
using namespace std;

operating_enter::operating_enter(this_data* somedata) :operating(somedata) {};

void operating_enter::Cursor_handl() {

	this->operating_data->position->Y++;
	this->operating_data->position->X = 0 + OFFSET;
	
	return;
};
int operating_enter::Data_handl() {
	return 0;
};

void operating_enter::Run() {

	row_data Previous_Y = (*(this->operating_data->table))[this->operating_data->position->Y];
	splstd Previous_splstd = Previous_Y.splsta_data;
	COORD Previous_position_xy;

	Previous_position_xy.X = this->operating_data->position->X;
	Previous_position_xy.Y = this->operating_data->position->Y;
	bool empty_next_X = Previous_Y.length == Previous_position_xy.X - OFFSET ? TRUE : FALSE;
	bool empty_next_Y = this->operating_data->table->size() == Previous_position_xy.Y + 1 ? TRUE : FALSE;
	
	//计算下一行的总格数,并把当前行数置为更改后的总格数
	int next_row_length = Previous_Y.length - (Previous_position_xy.X - OFFSET);
	(*(this->operating_data->table))[this->operating_data->position->Y].length = Previous_position_xy.X - OFFSET;

	Cursor_handl();

	splstd next_lstd(new lstd());
	

	SET_POSITION(Previous_position_xy);
	if (!empty_next_X) {
		lstd_lt Cut_points = Previous_splstd->begin();
		int upmove = Cut_points->coding_flags;
		for (; upmove <= Previous_position_xy.X - OFFSET;upmove+=Cut_points->coding_flags ) {
			Cut_points++; 
		}
		//在横坐标上不是最后一行时输出回车
		Cout_have_next_X(Cut_points, Previous_splstd);	

		next_lstd->splice(next_lstd->begin(), *(Previous_splstd), Cut_points, Previous_splstd->end());
	}

	
	if (empty_next_Y) {

		SET_POSITION(*this->operating_data->position);
		this->operating_data->table->push_back({ next_lstd ,next_row_length });
		lstd_lt Cut_points = next_lstd->begin();

		//回车后下一行为最后一行时输出
		for (Cut_points; Cut_points != next_lstd->end(); Cut_points++)
			wcout << Cut_points->text;
	}
	else {
		this->operating_data->table->insert(this->operating_data->table->begin()+\
			this->operating_data->position->Y, { next_lstd,next_row_length });
		//回车后下一行不是最后一行时输出
		Cout_have_next_Y(Previous_position_xy);
	}

	

	SET_POSITION(*this->operating_data->position);
	
	
	return;

};



void operating_enter::Cout_have_next_X(lstd_lt& cout_poin, splstd& cut_poin) {
	for (lstd_lt Cut_points_remain = cout_poin\
		; Cut_points_remain != cut_poin->end(); \
		Cut_points_remain++) {
		for (int count = 0; count < Cut_points_remain->coding_flags;count++) {
			wcout << " ";
		}
	}
	return;
};

//如果回车后的下一行不是最后一行调用该方法
void operating_enter::Cout_have_next_Y(COORD &Previous_position_xy) {

	COORD this_coord;
	this_coord = Previous_position_xy;
	this_coord.X = 0 + OFFSET;
	this_coord.Y++;
	SET_POSITION(this_coord);
	int now_int;

	//遍历更改过的每一行
	for (dlsptd_lt first = this->operating_data->table->begin() + \
		this->operating_data->position->Y\
		; first != this->operating_data->table->end(); first++) {

		if (first != this->operating_data->table->end() - 1) {
			now_int = 0;
		}	

		
		for (lstd_lt second = (*first).splsta_data->begin(); second != (*first).splsta_data->end(); now_int+=second->coding_flags,second++)
			wcout << second->text;
		if (first != this->operating_data->table->end() - 1) {
				for (; now_int < (first+1)->length; now_int++) {
					wcout << " ";
				}
		}
		this_coord.Y++;
		SET_POSITION(this_coord);
	}


};