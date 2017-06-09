#include<deque>
#include<list>
#include<set>
#include<boost/shared_ptr.hpp>
#pragma pack(push,_CRT_PACKING)
#ifdef _CRT_PACKING
	#define _CRT_PACKING 8
#endif

#define OFFSET  4//ƫ����

#define OFFSET_NUM OFFSET-4 //���ƫ����

#define CTRL_KEY 0xE0
#define CTRL_LEFT 0x4B
#define CTRL_RIGHT 0x4D
#define CTRL_DOWN 0x50
#define CTRL_UP 0x48
#define Enter 0x0D 
#define Backspace 0x08
#define Space 0x20
#define CTRL_S 0x13
#define ESC 0x1B
#define It_Char_Begin  20 
#define It_Char_End 126



//#define ESSENTIAL_SPACE 0
#define ESSENTIAL_remark (wchar_t)'/'
//#define ESSENTIAL_FIRST 1


#if IN_WHERE==IN_WIN
#define SET_POSITION(position) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position)
#define SET_COLOR(color)   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color)
#define SET_CLS system("CLS")
#define SET_BUFFERSIZE(size) SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);
#endif





//�����ʽ���͵�ѡ�� 
//��������Ҫ����ռλ��,Ӣ��һ��
#define EN 1
#define CH 2

struct table_data {

	int colour_flags; //��ɫλ
	short coding_flags; //����λ(Ӣ��,����.....)
	int essential_flags; //�ؼ���λ ��λ���ڲ��ȷ���ؼ��������Ƿ������ʾ��
	wchar_t text;   //�洢�����ַ�
	

};


typedef std::list<table_data> lstd;
typedef boost::shared_ptr<lstd> splstd;

struct row_data {
	splstd splsta_data;   //ÿһ�е�����
	int length;   //ÿһ�е��ܸ���(����������ռ������Ӣ��һ��) 
};


typedef std::deque<row_data> dlsptd;
typedef lstd::iterator lstd_lt;
typedef dlsptd::iterator dlsptd_lt;

typedef  std::wfstream file_type;
typedef std::multiset<int> setit;


namespace  operating_data {
	struct data {
		int* text;
		short coding_flags;
		COORD* position;
		dlsptd* table;
	};
}

