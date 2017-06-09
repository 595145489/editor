#include<stdafx.h>
#include<operating.h>
using namespace std;
operating_getchar::operating_getchar(this_data* somedata):operating(somedata) {};


//operating_getchar* operating_getchar::transfer(this_data* somedata) {
//	static operating_getchar x(somedata);
//	return &x;
//};


void operating_getchar::Run() {

	splstd this_splstd = (*(this->operating_data->table))[this->operating_data->position->Y].splsta_data;
	lstd_lt move= this_splstd->begin();
	for (int upmove = 0;upmove< (this->operating_data->position->X - OFFSET);) {
		upmove += move->coding_flags;
		move++;
	}

	


	//�����ʽ���͵�ѡ�� 
	
	if (*(this->operating_data->text) <= It_Char_Begin || *(this->operating_data->text) >= It_Char_End) {
		this->coding = CH;
	}
	else {
		 this->coding = EN;
	}

	//if (*(this->operating_data->text) == Space) {
	//	essential_flags = ESSENTIAL_SPACE;
	//}
	//else {
	//	essential_flags = ESSENTIAL_FIRST;
	//}

	this->operating_data->coding_flags = this->coding;

	//�ؼ��ʵ���ϵı�־λ
	int essential_flags;
	//��ɫλ������Ⱦ
	int colour ;
	
	//�����move��ǰ��Ϊmove-1 ����ĺ���Ϊmove����
	call_back num = this->grammar->Get_It_getchar(this_splstd,move, *(this->operating_data->text));
	essential_flags = num.essential_flags;
	colour = num.color_flags;


	this_splstd->insert(move, { colour, this->coding, essential_flags ,(wchar_t)*(this->operating_data->text) });
	//�Ѹոռ����ַ��ĵ�Ԫ�����ܳ�����
	(*(this->operating_data->table))[this->operating_data->position->Y].length += this->coding;
	move--;
	for (; move != this_splstd->end(); move++) {
		wcout << move->text;
	}
	
	this->Cursor_handl();
	SET_POSITION(*this->operating_data->position);

	return;
};


void operating_getchar::Cursor_handl() {


	this->operating_data->position->X+=this->coding;


	
	return;
};


void operating_getchar::Get_grammar(Explanation* grammar) {
	this->grammar = grammar;
	return;
}

int  operating_getchar::Data_handl() {
	return 0;
};


