#include<stdafx.h>
#include<operating.h>

operating_down::operating_down(this_data* somedata) :operating(somedata) {};

void operating_down::Cursor_handl() {

	//如果Y向下仍然有函数,则向下移动一行,否则说明向下已经没有,则不做任何改动
	if (this->operating_data->table->size() != this->operating_data->position->Y+1) {

		this->operating_data->position->Y++;

		splstd this_splstd = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
		lstd_lt move = this_splstd->begin();

		int upmove = 0, change_x = 1, size = this_splstd->size();

		//如果向下移动一行后,该行长度比现在的X值小或者相等，则直接向上移动到该行的最后你一格+偏移量
		if ((*(this->operating_data->table))[this->operating_data->position->Y].length<= this->operating_data->position->X - OFFSET) {
			this->operating_data->position->X = (*(this->operating_data->table))[this->operating_data->position->Y].length + OFFSET;
			return;
		}

		for (; upmove + move->coding_flags <= (this->operating_data->position->X - OFFSET) && change_x <= size\
			; ++change_x) {
			upmove += move->coding_flags;
			move++;
			//此处是为了判别是在最后一个数据的向上移动还是在最后一个数据的下一个（即最末尾向上移动）
			if (move == this_splstd->end()) {
				break;
			}
		}
		this->operating_data->position->X = upmove + OFFSET;
	}
		
	return;
};
int operating_down::Data_handl() {
	return 0;
};

void operating_down::Run() {
	Cursor_handl();
	SET_POSITION(*this->operating_data->position);
};

