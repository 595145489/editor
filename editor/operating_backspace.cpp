#include<stdafx.h>
#include<operating.h>
using namespace std;

operating_backspace::operating_backspace(this_data* somedata) :operating(somedata) {};

void operating_backspace::Cursor_handl() {
	
	if (this->operating_data->position->X == 0 + OFFSET && this->operating_data->position->Y) {
		this->operating_data->position->Y--;
		this->operating_data->position->X = \
			(*(this->operating_data->table))[this->operating_data->position->Y ].length\
			+ OFFSET;
	}
	else if(this->operating_data->position->X != 0 + OFFSET ) {
		this->operating_data->position->X--;
	}
	

	return;
};
int operating_backspace::Data_handl() {
	return 0;
};

void operating_backspace::Run() {

	
	
	
	//������ڵĺ�����-ƫ������Ϊ0,���ɾһ����λ
	if (this->operating_data->position->X - OFFSET ) {

		Cursor_handl();
		splstd  this_splstd = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
		lstd_lt this_lstdit = this_splstd->begin();
		//���ڱ��벻ͬ,Cursor_handlͳһ���޼�һ����λ�������ڴ˴���Ҫ�����������������ַ��ĵ�λ��
  		for (int num = this_lstdit->coding_flags; num <= this->operating_data->position->X - OFFSET - this_lstdit->coding_flags + 1\
			; num+= this_lstdit->coding_flags, this_lstdit++) {};

		lstd_lt new_lstdit = this_lstdit;
		new_lstdit++;
		this->operating_data->coding_flags = this_lstdit->coding_flags;
		//�˴��������ַ��ĵ�λ���ȥ
		this->operating_data->position->X -= this_lstdit->coding_flags - 1;
		(*(this->operating_data->table))[this->operating_data->position->Y].length -= this_lstdit->coding_flags;
		this_splstd->erase(this_lstdit);
		
		Cout_have_previous_X(new_lstdit, this_splstd);

	}	
	//������ڵĺ�����-ƫ����Ϊ0��Y��Ϊ0�����ϻ�ɾһ��,����,�����κθĶ�
	else if (this->operating_data->position->Y) {

		Cursor_handl();
		

		splstd previous_splstd = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
		splstd delete_splstd = (*(this->operating_data->table))[this->operating_data->position->Y+1 ].splsta_data;
		
		lstd_lt delete_lt;
		int size = (*(this->operating_data->table))[this->operating_data->position->Y + 1].length;
		if (size) {
			delete_lt = delete_splstd->begin();
		}
		
		//������ɾ���е��ܸ�������һ�����
		(*(this->operating_data->table))[this->operating_data->position->Y].length += \
			(*(this->operating_data->table))[this->operating_data->position->Y + 1].length;

		previous_splstd->splice(previous_splstd->end(), *delete_splstd, \
			delete_splstd->begin(), delete_splstd->end());
		this->operating_data->table->erase(this->operating_data->table->begin()+\
			this->operating_data->position->Y+1);

		SET_POSITION(*this->operating_data->position);
		COORD next = *this->operating_data->position;
		if (size) {
			for (; delete_lt != previous_splstd->end(); delete_lt++) wcout << delete_lt->text;
		}
		
		Cout_have_previous_Y(next,size);
	}


	
	SET_POSITION(*this->operating_data->position);



	return;

};



void operating_backspace::Cout_have_previous_X(lstd_lt& cout_poin, splstd& cut_poin) {

	SET_POSITION(*this->operating_data->position);
	for (;cout_poin!=cut_poin->end(); cout_poin++) {
		wcout << cout_poin->text;
	}
	//�˴����޸�,����дfor���붯��
	wcout << "                                        ";
	return;
};

void operating_backspace::Cout_have_previous_Y(COORD &next_position_xy,int& size) {

	next_position_xy.X = 0 + OFFSET;
	int now_Y = ++next_position_xy.Y;
	SET_POSITION(next_position_xy);
	int count = 0;

	for (dlsptd_lt first = this->operating_data->table->begin()+ now_Y \
		; first!=this->operating_data->table->end(); first++) {
		
		for (lstd_lt second = (*first).splsta_data->begin() ;\
			second!=(*first).splsta_data->end(); second++,count++) {
			wcout << second->text;
		}
		if (count<size) {
			for (;count<size;count++) {
				wcout << " ";
			}
		}

		size = (*first).length;

		
		next_position_xy.Y++;
		count = 0;
		SET_POSITION(next_position_xy);
	}

	size = (*(this->operating_data->table->end() - 1)).length;
	for (; count <= size; count++) {
		wcout << " ";
	}

	return;
};