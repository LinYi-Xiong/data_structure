#pragma once
#include <iostream>

namespace myLinkList {
#ifndef LIST_H_
#define LIST_H_


	/*
		ѭ���������Ҫ����ģ��
		ѭ������������ǵ�һ��Ҳ�����һ��
	*/
	/*-----------------------------------------------------*/
	class List
	{
	public:
		List();
		~List();

		//��ʼ�����뷽ʽ
		void init(int howIn);
		//�������
		void add(int type);
		//չʾ����
		void showTypes();
		//��������
		void insert(int t_where, int type);
		//�޸�����
		void change(int t_where, int type);
		//ɾ���ڵ�
		void deleteType(int t_where);
		//��������
		int findType(int type);
		//�Ƿ�Ϊ��
		std::string isEmpty();
		//��������
		int quantity();


	private:
		//�ڵ�ṹ��
		typedef struct node {
			struct node* p_left;
			struct node* p_right;
			int type;
		}Node;

		int howIn = -1;
		int count = 0;
		//��һ����ӵ�����Ľڵ�
		Node* p_flog;
		//��ʼ���ڵ�
		Node* p_initNode();
		//��ӵ�һ���ڵ�
		void addFirst(node* needIn, int type);
		//β�巨���뵽����
		void tailAdd(int type);
		//Ǥ�巨���뵽����
		void forwordAdd(int type);
		//�������
		bool ascFind(int* t_where, int type);
		//���򶨵����
		Node* ascFinding(int t_where);
	};
	/*--------------PUBLIC-------------------------------*/

	//��ʼ������
	//����ʼֵΪ1ʱʹ��ǰ�巨����
	//����ʼֵΪ0ʱʹ��β�巨����
	List::List()
	{
		p_flog = p_initNode();
	}
	//��ʼ�����뷽ʽ
	void List::init(int howIn) {
		this->howIn = howIn;
	}
	//��ʼ���ڵ�
	List::Node* List::p_initNode() {
		Node* newNode = new Node();
		newNode->p_left = newNode;
		newNode->p_right = newNode;
		return newNode;
	}

	/*
	  �����������ڽ���ʱ���øú���
	  ����ڳ�����ʹ���� new �������Ķ������ڸú���λ��
	  ͳһ delete �ó���ɶ�������
	*/
	List::~List()
	{
		//delete p_flog;

		std::cout << "������ж��" << std::endl;
	}

	//�������
	void List::add(int type) {
		switch (howIn)
		{
		case 0:tailAdd(type); break;
		case 1:forwordAdd(type); break;
		default:break;
		}
	}

	//չʾ���������
	void List::showTypes() {
		Node* middle = p_flog;
		for (int i = 0; i < count; i++) {
			std::cout << "] " << i+1 << "> " << middle->type << std::endl;
			middle = middle->p_right;
		}
	}

	//��������
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
			std::cout << "�������ݳɹ�" << std::endl;
		}
		else if (t_where == 1) {
			forwordAdd(type);
			std::cout << "�������ݳɹ�" << std::endl;
		}
		else
			std::cout << "����Ľڵ�λ���쳣" << std::endl;
	}

	//�޸�����
	void List::change(int t_where, int type) {
		if (count >= 1)
		{
			if (t_where > 0 && t_where <= count) {
				Node* p_need = ascFinding(t_where);
				p_need->type = type;
				std::cout << "���ݲ���ɹ�" << std::endl;
			}
			else
				std::cout << "����Ľڵ�λ���쳣" << std::endl;
		}
		else
			std::cout << "�޷�ִ���޸Ĳ���" << std::endl;
	}

	//ɾ���ڵ�λ������
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
				std::cout << "��λ�����ݳɹ�ɾ��" << std::endl;
			}
			else if(count == 1)
			{
				p_flog->type = NULL;
				count--;
				std::cout << "��λ�����ݳɹ�ɾ��" << std::endl;
			}
			else
				std::cout << "�޷�ִ��ɾ������" << std::endl;
		}
		else
			std::cout << "����Ľڵ�λ���쳣" << std::endl;
		
	}

	//��������
	int List::findType(int type) {

		int t_where = -1;
		if(count>=1)
			if (ascFind(&t_where, type))
				return t_where;
		return -1;
	}

	//�Ƿ�Ϊ�� : true Ϊ�� false ��Ϊ��
	std::string List::isEmpty() {
		if (count == 0)
			return "is null";
		else
			return "not is null";
	}

	//��������
	int List::quantity() {
		return count;
	}



	/*---------PRIVATE---------------*/
	//β�巨��ӵ�ѭ������ ���д��� 0
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

	//ǰ�巨���뵽���� ���д��� 1
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

	//��ӵ�һ���ڵ�
	void List::addFirst(node* needIn, int type) {
		needIn->p_right = needIn->p_left = needIn;
		needIn->type = type;
		p_flog = needIn;
		p_flog->p_right = p_flog;
	}
	//�������λ��
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

	//���򶨵����
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