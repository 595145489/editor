#pragma once



struct call_back {
	int color_flags;
	int essential_flags;
};

class Explanation {

public:
	Explanation::Explanation();
	call_back Get_It_getchar(splstd, lstd_lt, int); //键入参数为当前行的
	Explanation::~Explanation();
private:
	void Select_essential();
	void Config_essential();
};