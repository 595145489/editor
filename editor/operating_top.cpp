#include<stdafx.h>
#include<operating.h>

operating_top::operating_top(this_data* somedata) :operating(somedata) {};

void operating_top::Cursor_handl() {

	//���Y��Ϊ0����������ƶ�һ��,����ֱ�ӷ���
	if (this->operating_data->position->Y) {

		this->operating_data->position->Y--;
		splstd this_splstd = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
		lstd_lt move = this_splstd->begin();

		int upmove = 0, change_x = 1, \
			size = this_splstd->size();
		//��������ƶ�һ�к�,���е��ܳ��ȱ����ڵ�XС�������,�������ƶ������һ��
		if ((*(this->operating_data->table))[this->operating_data->position->Y].length <= this->operating_data->position->X - OFFSET) {
			this->operating_data->position->X = (*(this->operating_data->table))[this->operating_data->position->Y].length + OFFSET;
			return;
		}

		for (; upmove+ move->coding_flags <= (this->operating_data->position->X - OFFSET)&&change_x<=size\
			;++change_x) {
			upmove += move->coding_flags;
			move++;
			//�˴���Ϊ���б��������һ�����ݵ������ƶ����������һ�����ݵ���һ��������ĩβ�����ƶ���
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

