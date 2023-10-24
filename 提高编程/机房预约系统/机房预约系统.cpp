#include <iostream>
#include <string>
using namespace std;

#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include <fstream>

//管理员菜单
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//管理员菜单
		manager->operMenu();

		Manager* man = (Manager*)manager;
	}
}



//全局函数实现登录
void LoginIn(string filename, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)  //教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登录验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份子菜单
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证int fid;
		int empfid;
		string fname;
		string fpwd;
		while (ifs >> empfid && ifs >> fname && ifs >> fpwd)
		{
			if (empfid == id && fname == name && fpwd == pwd)
			{
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份子菜单
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登陆验证
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if ( fname == name && fpwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager( name, pwd);
				//进入管理员身份子菜单
				return;
			}
		}
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;

}



int main()
{
	int select = 0;
	while (true)
	{
		cout << "------------欢迎来到机房预约系统---------------" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t|------------------------------------|\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|         1.学生代表                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|         2.老    师                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|         3.管 理 员                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|         0.退    出                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|------------------------------------|\n";

		cout << "输入您的选择:";
		cin >> select;    //接受用户选择
		switch (select)
		{
		case 1: //学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:   //管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:   //退出
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}


	system("pause");
	return 0;
}