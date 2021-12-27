#pragma once
#include <iostream>

namespace myLinkList {
#ifndef LIST_H_
#define LIST_H_


	/*
		循环链表的主要功能模块
		循环链表的旗帜是第一个也是最后一个
	*/
	/*-----------------------------------------------------*/
	class List
	{
	public:
		List();
		~List();

		//初始化插入方式
		void init(int howIn);
		//添加数据
		void add(int type);
		//展示数据
		void showTypes();
		//插入数据
		void insert(int t_where, int type);
		//修改数据
		void change(int t_where, int type);
		//删除节点
		void deleteType(int t_where);
		//查找数据
		int findType(int type);
		//是否为空
		std::string isEmpty();
		//数据数量
		int quantity();


	private:
		//节点结构体
		typedef struct node {
			struct node* p_left;
			struct node* p_right;
			int type;
		}Node;

		int howIn = -1;
		int count = 0;
		//第一个添加到链表的节点
		Node* p_flog;
		//初始化节点
		Node* p_initNode();
		//添加第一个节点
		void addFirst(node* needIn, int type);
		//尾插法插入到链表
		void tailAdd(int type);
		//扦插法插入到链表
		void forwordAdd(int type);
		//正序查找
		bool ascFind(int* t_where, int type);
		//正序定点查找
		Node* ascFinding(int t_where);
	};
	/*--------------PUBLIC-------------------------------*/

	//初始化链表
	//当初始值为1时使用前插法插入
	//当初始值为0时使用尾插法插入
	List::List()
	{
		p_flog = p_initNode();
	}
	//初始化插入方式
	void List::init(int howIn) {
		this->howIn = howIn;
	}
	//初始化节点
	List::Node* List::p_initNode() {
		Node* newNode = new Node();
		newNode->p_left = newNode;
		newNode->p_right = newNode;
		return newNode;
	}

	/*
	  当类生命周期结束时调用该函数
	  如果在程序中使用了 new 来创建的对象则在该函数位置
	  统一 delete 让程序可读性增加
	*/
	List::~List()
	{
		//delete p_flog;

		std::cout << "链表已卸载" << std::endl;
	}

	//添加数据
	void List::add(int type) {
		switch (howIn)
		{
		case 0:tailAdd(type); break;
		case 1:forwordAdd(type); break;
		default:break;
		}
	}

	//展示存入的数据
	void List::showTypes() {
		Node* middle = p_flog;
		for (int i = 0; i < count; i++) {
			std::cout << "] " << i+1 << "> " << middle->type << std::endl;
			middle = middle->p_right;
		}
	}

	//插入数据
	void List::insert(int t_where, int type) {

		if (t_where > 1 && t_where <= count) {
			
			Node* p_need = ascFinding(t_where);
			Node* p_new = p_initNode();	

			p_new->p_left = p_need->p_left;			
			p_new->p_right = p_need;
			p_need->p_left->p_right = p_new;
			p_need->p_left = p_new;

			p_new->type = type;
			count++;
			std::cout << "插入数据成功" << std::endl;
		}
		else if (t_where == 1) {
			forwordAdd(type);
			std::cout << "插入数据成功" << std::endl;
		}
		else
			std::cout << "输入的节点位置异常" << std::endl;
	}

	//修改数据
	void List::change(int t_where, int type) {
		if (count >= 1)
		{
			if (t_where > 0 && t_where <= count) {
				Node* p_need = ascFinding(t_where);
				p_need->type = type;
				std::cout << "数据插入成功" << std::endl;
			}
			else
				std::cout << "输入的节点位置异常" << std::endl;
		}
		else
			std::cout << "无法执行修改操作" << std::endl;
	}

	//删除节点位置数据
	void List::deleteType(int t_where) {
		if (t_where > 0 && t_where <= count) {
			if (count > 1)
			{			
				Node* p_need = ascFinding(t_where);
				p_need->p_left->p_right = p_need->p_right;
				p_need->p_right->p_left = p_need->p_left;
				delete p_need;
				p_need = NULL;
				count--;
				std::cout << "该位置数据成功删除" << std::endl;
			}
			else if(count == 1)
			{
				p_flog->type = NULL;
				count--;
				std::cout << "该位置数据成功删除" << std::endl;
			}
			else
				std::cout << "无法执行删除操作" << std::endl;
		}
		else
			std::cout << "输入的节点位置异常" << std::endl;
		
	}

	//查找数据
	int List::findType(int type) {

		int t_where = -1;
		if(count>=1)
			if (ascFind(&t_where, type))
				return t_where;
		return -1;
	}

	//是否为空 : true 为空 false 不为空
	std::string List::isEmpty() {
		if (count == 0)
			return "is null";
		else
			return "not is null";
	}

	//数据数量
	int List::quantity() {
		return count;
	}



	/*---------PRIVATE---------------*/
	//尾插法添加到循环链表 运行代码 0
	void List::tailAdd(int type) {

		node* p_needIn = p_initNode();
		p_needIn->type = type;
		if (count == 0)
		{
			addFirst(p_needIn, type);
		}//#if
		else if (count > 0)
		{
			p_needIn->p_left = p_flog->p_right;
			p_needIn->p_right = p_flog;
			p_needIn->type = type;
			p_flog->p_left = p_needIn;
			p_flog->p_right->p_right = p_needIn;
			p_flog->p_right = p_needIn;
		}//#eif
		count++;

	}//#tailadd

	//前插法插入到链表 运行代码 1
	void List::forwordAdd(int type)
	{

		node* p_needIn = p_initNode();
		p_needIn->type = type;
		if (count == 0)
		{
			addFirst(p_needIn, type);
		}//#if
		else if (count > 0)
		{
			p_needIn->p_left = p_flog->p_left;
			p_needIn->p_right = p_flog;
			p_needIn->type = type;
			p_flog = p_needIn;
		}//eif
		count++;

	}//#forwordadd

	//添加第一个节点
	void List::addFirst(node* needIn, int type) {
		needIn->p_right = needIn->p_left = needIn;
		needIn->type = type;
		p_flog = needIn;
		p_flog->p_right = p_flog;
	}
	//正序查找位置
	bool List::ascFind(int* t_where, int type) {
		Node* p_find = p_flog;
		for (int i = 1; i <= count; i++) {
			if (p_find->type == type) {
				*t_where = i;
				return true;
			}
			p_find = p_find->p_right;
		}
		return false;
	}

	//正序定点查找
	List::Node* List::ascFinding(int t_where) {
		Node* p_find = p_flog;
		for (int i = 0; i < t_where; i++) {
			p_find = p_find->p_right;
		}
		return p_find->p_left;
	}
#endif // !LIST_H_
}
/*-----------END------------*/