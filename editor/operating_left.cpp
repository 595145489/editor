#include<stdafx.h>
#include<operating.h>

operating_left::operating_left(this_data* somedata) :operating(somedata) {};

void operating_left::Cursor_handl() {

	splstd this_splstd;
	lstd_lt move;

	//�������������X-ƫ������Ϊ0�������ƶ�һ���ַ���λ
	if (this->operating_data->position->X - OFFSET) {

		this_splstd  = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
		move = this_splstd->begin();

		for (int upmove = move->coding_flags; upmove< (this->operating_data->position->X - OFFSET); ) {
			move++;
			upmove += move->coding_flags;
			
		}
		this->operating_data->position->X-=move->coding_flags;
	}
	//���X-ƫ����Ϊ0����Y��Ϊ0 ����Y-1���ƶ�������ĩβ
	else if (this->operating_data->position->Y) {

		this->operating_data->position->Y--;
		this->operating_data->position->X = OFFSET + (*(this->operating_data->table))[this->operating_data->position->Y].length;
		//this_splstd = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
		//move = this_splstd->begin();
		//if (!this_splstd->size()) { //�����һ���е�Xû��������ֱ�ӷ���,��X=0+ƫ����
		//	this->operating_data->position->X = OFFSET;
		//	return;
		//}

		////�����һ�е�X������
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

