#include<stdafx.h>



Explanation::Explanation() {};
Explanation::~Explanation() {};
void Explanation::Select_essential() {};

//传入的move的前置为move-1 传入的后置为move本身
call_back Explanation::Get_It_getchar(splstd this_splstd, lstd_lt move, int text) {

	//this_essential > 0 表示正常字符,0为空格,-1为注释符,-2为注释内容
	int this_color = 1, this_essential;

	

	//前置检查
	if (move != this_splstd->begin()) { //如果当前目标没有上一个,则不用检查上一个
		lstd_lt before = move;
		before--;
		if (before->essential_flags > 0) { //如果上一个为正常字符的情

			//如果上一个字符为注释符的情况下需要区分两种情况,第一种是键入下一个字符也为注释符,另一个是为普通字符的情况
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
			else if (text == Space) { //如果本次输入为空格的情况
				this_essential = 0;
			}
			else
				this_essential = before->essential_flags + 1;

		}
		else if (before->essential_flags == 0) { //如果上一个为空格的情况
			if (text == Space) {
				this_essential = 0;
			}
			else {
				this_essential = 1;
			}
		}
		else //如果为注释的情况                                                                                                                                                                           
			this_essential = -2;
	}
	else {
		if (text == Space)
			this_essential = 0;
		else
			this_essential = 1;
	}
	//前置检查end

	//后置检查

	if (move != this_splstd->end()) { //如果下一个不为最后一个的情况

		lstd_lt Rear = move;

		//检查他的下一位是否同为注释符,如果是则更改状态
		if (Rear->text == ESSENTIAL_remark && text == ESSENTIAL_remark) {
			this_essential = -1;
			Rear->essential_flags = -1;
			Rear++;
		}

		if (this_essential > 0) {  // 如果键入字符不为空格

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
		else if (this_essential == -1) { //如果刚添加的为注释, 则后面所有的东西全部为注释内容
			for (; Rear != this_splstd->end();Rear++) {
				Rear->essential_flags = -2;
			}
		}
	}

	//后置检查end
	return{ this_color,this_essential };
};


void Explanation::Config_essential() {};