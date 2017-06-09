#pragma once
class Help {
public:
	bool Run(std::string);
protected:
	virtual void Cin_help() {};
	virtual void Cin_new_file() {};
	virtual void Cin_open_file() {};
};


class Console_Help :public Help {
private:
	void Cin_help();
	void Cin_new_file();
	void Cin_open_file();
};