#include<stdafx.h>
#include<operating.h>

operating_left::operating_left(this_data* somedata) :operating(somedata) {};

void operating_left::Cursor_handl() {

	splstd this_splstd;
	lstd_lt move;

	//如果在所在坐标X-偏移量不为0则向左移动一个字符单位
	if (this->operating_data->position->X - OFFSET) {

		this_splstd  = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
		move = this_splstd->begin();

		for (int upmove = move->coding_flags; upmove< (this->operating_data->position->X - OFFSET); ) {
			move++;
			upmove += move->coding_flags;
			
		}
		this->operating_data->position->X-=move->coding_flags;
	}
	//如果X-偏移量为0而且Y不为0 则向Y-1且移动到改行末尾
	else if (this->operating_data->position->Y) {

		this->operating_data->position->Y--;
		this->operating_data->position->X = OFFSET + (*(this->operating_data->table))[this->operating_data->position->Y].length;
		//this_splstd = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
		//move = this_splstd->begin();
		//if (!this_splstd->size()) { //如果上一行行的X没有数据则直接返回,且X=0+偏移量
		//	this->operating_data->position->X = OFFSET;
		//	return;
		//}

		////如果上一行的X有数据
		//int change_x = move->coding_flags;
		//for (int upmove = move->coding_flags; upmove< this_splstd->size(); upmove++) {
		//	move++;
		//	change_x += move->coding_flags;
		//}
		//this->operating_data->position->X = change_x  + OFFSET;	
	}
	return;
};
int operating_left::Data_handl() {
	return 0;
};

void operating_left::Run() {

	

	Cursor_handl();
	SET_POSITION(*this->operating_data->position);

};

