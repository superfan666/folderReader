// AllFilesNamesGets.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<io.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

//获取指定文件夹中后缀为posfix的文件名，
void getFileNames(string path, vector<string>&files, const string postfix)
{
	intptr_t   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*"+postfix).c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之  
			//如果不是,加入列表  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFileNames(p.assign(path).append("\\").append(fileinfo.name), files,postfix);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
int main()
{
	vector<string>names;
	string path= "D:\\3D-reconstruction\\data";
	getFileNames(path, names, ".dcm");
	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i]<<endl;
	}

    return 0;
}

