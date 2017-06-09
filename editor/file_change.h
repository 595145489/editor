#pragma once


class File_Save {
public:
	typedef operating_data::data this_data;

	File_Save(file_type* file, this_data * operating_data) \
		:file(file),operating_data(operating_data){};
protected:
	void Save_ctrl_s();
	virtual ~File_Save() {};
	file_type* file;
	this_data * operating_data;
};


class File_Save_Conself:public File_Save{
public:
	File_Save_Conself(file_type* file, this_data * operating_data) \
		:File_Save(file, operating_data) {};
	void Run_ctrl_s();
	void Run_esc();
	~File_Save_Conself() {};
private:

	
};