#pragma once

class operating {
	
public:
	typedef operating_data::data this_data;
	
	virtual	void Run() = 0;
	template <typename operat>
	static operat* transfer(this_data*);
protected:
	virtual void Cursor_handl() = 0;
	//该接口用于单元测试
	virtual int Data_handl() { return 0; };
	operating::operating(this_data* somedata):operating_data(somedata) {};
	virtual operating::~operating() {};
	this_data  *operating_data;
};

template <typename operat>
operat* operating::transfer(this_data* somedata) {
	static operat x(somedata);
	return &x;
};



//输入普通英文\汉字与数字与空格
class operating_getchar : public operating{
public:
	//static operating_getchar* transfer(this_data*);
	void Cursor_handl();
	int Data_handl();
	void Run();
	void operating_getchar::Get_grammar(Explanation*);
private:
	friend operating;
	short coding; //中间编码传递 连接cursor_handl与run的变量
	Explanation* grammar;  //语法解释类

	operating_getchar(this_data*);
	~operating_getchar() {};
	operating_getchar(operating_getchar& copy) :operating(copy.operating_data) {};
};


//方向左键
class operating_left : public operating {
public:
	//static operating_left* transfer(this_data*);
	void Cursor_handl();
	int Data_handl();
	void Run();
private:
	friend operating;
	operating_left(this_data*);
	~operating_left() {};
	operating_left(operating_left& copy) :operating(copy.operating_data) {};
};


//方向左键
class operating_right : public operating {
public:
	//static operating_left* transfer(this_data*);
	void Cursor_handl();
	int Data_handl();
	void Run();
private:
	friend operating;
	operating_right(this_data*);
	~operating_right() {};
	operating_right(operating_right& copy) :operating(copy.operating_data) {};
};

//方向下键
class operating_top : public operating {
public:
	//static operating_left* transfer(this_data*);
	void Cursor_handl();
	int Data_handl();
	void Run();
private:
	friend operating;
	operating_top(this_data*);
	~operating_top() {};
	operating_top(operating_top& copy) :operating(copy.operating_data) {};


};
//方向下键
class operating_down : public operating {
public:
	//static operating_left* transfer(this_data*);
	void Cursor_handl();
	int Data_handl();
	void Run();
private:
	friend operating;
	operating_down(this_data*);
	~operating_down() {};
	operating_down(operating_down& copy) :operating(copy.operating_data) {};
};


//回车
class operating_enter : public operating {
public:
	//static operating_left* transfer(this_data*);
	void Cursor_handl();
	int Data_handl();
	void Run();
private:
	friend operating;
	operating_enter(this_data*);
	~operating_enter() {};
	operating_enter(operating_enter& copy) :operating(copy.operating_data) {};
	
	void Cout_have_next_X(lstd_lt&, splstd&);
	void Cout_have_next_Y(COORD&);
};


//退格
class operating_backspace : public operating {
public:
	//static operating_left* transfer(this_data*);
	void Cursor_handl();
	int Data_handl();
	void Run();
private:
	friend operating;
	operating_backspace(this_data*);
	~operating_backspace() {};
	operating_backspace(operating_backspace& copy) :operating(copy.operating_data) {};

	void Cout_have_previous_X(lstd_lt&, splstd&);
	void Cout_have_previous_Y(COORD&, int&);
};


//ESC键
class operating_esc : public operating {
public:
	//static operating_left* transfer(this_data*);
	void Cursor_handl();
	int Data_handl();
	void Run();
private:
	friend operating;
	operating_esc(this_data*);
	~operating_esc() {};
	operating_esc(operating_esc& copy) :operating(copy.operating_data) {};
};
