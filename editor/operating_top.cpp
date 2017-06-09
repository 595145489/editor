#include<stdafx.h>
#include<operating.h>

operating_top::operating_top(this_data* somedata) :operating(somedata) {};

void operating_top::Cursor_handl() {

	//如果Y不为0，则可向上移动一行,否则直接返回
	if (this->operating_data->position->Y) {

		this->operating_data->position->Y--;
		splstd this_splstd = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
		lstd_lt move = this_splstd->begin();

		int upmove = 0, change_x = 1, \
			size = this_splstd->size();
		//如果向上移动一行后,该行的总长度比现在的X小或者相等,则向上移动到最后一个
		if ((*(this->operating_data->table))[this->operating_data->position->Y].length <= this->operating_data->position->X - OFFSET) {
			this->operating_data->position->X = (*(this->operating_data->table))[this->operating_data->position->Y].length + OFFSET;
			return;
		}

		for (; upmove+ move->coding_flags <= (this->operating_data->position->X - OFFSET)&&change_x<=size\
			;++change_x) {
			upmove += move->coding_flags;
			move++;
			//此处是为了判别是在最后一个数据的向上移动还是在最后一个数据的下一个（即最末尾向上移动）
			if (move == this_splstd->end()) {
				break;
			}	
		}
		this->operating_data->position->X = upmove+OFFSET;
	}
	return;
};
int operating_top::Data_handl() {
	return 0;
};

void operating_top::Run() {
	Cursor_handl();
	SET_POSITION(*this->operating_data->position);
};

