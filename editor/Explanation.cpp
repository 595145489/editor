#include<stdafx.h>



Explanation::Explanation() {};
Explanation::~Explanation() {};
void Explanation::Select_essential() {};

//�����move��ǰ��Ϊmove-1 ����ĺ���Ϊmove����
call_back Explanation::Get_It_getchar(splstd this_splstd, lstd_lt move, int text) {

	//this_essential > 0 ��ʾ�����ַ�,0Ϊ�ո�,-1Ϊע�ͷ�,-2Ϊע������
	int this_color = 1, this_essential;

	

	//ǰ�ü��
	if (move != this_splstd->begin()) { //�����ǰĿ��û����һ��,���ü����һ��
		lstd_lt before = move;
		before--;
		if (before->essential_flags > 0) { //�����һ��Ϊ�����ַ�����

			//�����һ���ַ�Ϊע�ͷ����������Ҫ�����������,��һ���Ǽ�����һ���ַ�ҲΪע�ͷ�,��һ����Ϊ��ͨ�ַ������
			if (before->text == ESSENTIAL_remark ) {
				if (text == ESSENTIAL_remark) {
					this_essential = -1;
					before->essential_flags = -1;
				}
				else {
					int num = --before->essential_flags;
					++before->essential_flags = ++num;
					if (text == Space) {
						this_essential = 0;
						num = 0;
					}
					else
						this_essential = ++num;
				}
			}   
			else if (text == Space) { //�����������Ϊ�ո�����
				this_essential = 0;
			}
			else
				this_essential = before->essential_flags + 1;

		}
		else if (before->essential_flags == 0) { //�����һ��Ϊ�ո�����
			if (text == Space) {
				this_essential = 0;
			}
			else {
				this_essential = 1;
			}
		}
		else //���Ϊע�͵����                                                                                                                                                                           
			this_essential = -2;
	}
	else {
		if (text == Space)
			this_essential = 0;
		else
			this_essential = 1;
	}
	//ǰ�ü��end

	//���ü��

	if (move != this_splstd->end()) { //�����һ����Ϊ���һ�������

		lstd_lt Rear = move;

		//���������һλ�Ƿ�ͬΪע�ͷ�,����������״̬
		if (Rear->text == ESSENTIAL_remark && text == ESSENTIAL_remark) {
			this_essential = -1;
			Rear->essential_flags = -1;
			Rear++;
		}

		if (this_essential > 0) {  // ��������ַ���Ϊ�ո�

			int changnum = this_essential;
			for (; Rear!= this_splstd->end(); changnum++, Rear++) {
				if (Rear->essential_flags == 0 || Rear->essential_flags == -1) {

				}
				Rear->essential_flags = changnum;
			}
		}
		else if (this_essential == 0) {

			int Previous_flags = this_essential;

			for (; Rear != this_splstd->end(); Rear++) {
				if (Rear->text == Space) {
					Previous_flags = 0;
					Rear->essential_flags = 0;
					continue;
				}
				else if (Rear->essential_flags == -1)
					break;
				else {
					Rear->essential_flags = ++Previous_flags;
				}
			}
		}
		else if (this_essential == -1) { //�������ӵ�Ϊע��, ��������еĶ���ȫ��Ϊע������
			for (; Rear != this_splstd->end();Rear++) {
				Rear->essential_flags = -2;
			}
		}
	}

	//���ü��end
	return{ this_color,this_essential };
};


void Explanation::Config_essential() {};