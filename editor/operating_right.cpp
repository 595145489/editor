#include<stdafx.h>
#include<operating.h>


operating_right::operating_right(this_data* somedata) :operating(somedata) {};



//代码有点乱,需要调整
void operating_right::Cursor_handl() {


	int change_x = 0,size = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data->size();

	splstd this_splstd = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
	lstd_lt move = this_splstd->begin();//(this->operating_data->position->X - OFFSET);

	if (move != this_splstd->end()) {
		if(size!=1|| (this->operating_data->position->X - OFFSET))
			change_x=1 ;
		for (int upmove = move->coding_flags; upmove < (this->operating_data->position->X - OFFSET); change_x++) {
			move++;
			upmove += move->coding_flags;
		}	
	}


 	if (size == change_x) {
		if (this->operating_data->table->size() != this->operating_data->position->Y + 1) {
			this->operating_data->position->X = 0 + OFFSET;
			this->operating_data->position->Y++;
		}
	}
	else {
		if ((this->operating_data->position->X - OFFSET)) 
			move++;
		this->operating_data->position->X += move->coding_flags;
	}
	

	return;
};
int operating_right::Data_handl() {
	return 0;
};

void operating_right::Run() {

	Cursor_handl();
	SET_POSITION(*this->operating_data->position);

};
