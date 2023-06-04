//============================================================================
// Name        : StudentSystem.cpp
// Author      : chiyu
// Version     : 
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

#define NO_LENGTH  20
#define NAME_LENGTH 11

/* ����ѧ���ṹ������ݽṹ */
typedef struct Student{
	char studentNo[NO_LENGTH];
	char studentName[NAME_LENGTH];
}st;

/* ����ÿ����¼��ڵ�����ݽṹ */
typedef struct node
{
	struct Student data; //������
	struct node *next; //ָ����
}Node,*Link;  //NodeΪnode���͵ı���,LinkΪnode���͵�ָ�����

//������ʾ�˵�
void myMenu(){
	printf(" * * * * * * * * * ��     �� * * * * * * * * * *\n");
	printf("     1 ����ѧ����¼            2 ɾ��ѧ����¼                     \n");
	printf("     3 ����ѧ����¼            4 �޸�ѧ����¼                     \n");
	printf("     5 ͳ��ѧ������            6 ��ʾѧ����¼                     \n");
	printf("     7 �˳�ϵͳ                                     \n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

void inputStudent(Link l){
	 printf("������ѧ��ѧ��:");
	 scanf("%s",l->data.studentNo);
	 printf("������ѧ��������:");
	 scanf("%s",l->data.studentName);

	 //ÿ���´����Ľڵ��next�򶼳�ʼ��ΪNULL
	 l->next = NULL;
}

void inputStudentNo(char s[],char no[]){
	printf("������Ҫ%s��ѧ��ѧ��:",s);
	scanf("%s",no);
}

void displayNode(Link head){
   // ��д���룬���ݴ��������headͷָ�룬ɨ��������ʾ���нڵ����Ϣ
}

/* ����ѧ����¼ */
bool addNode(Link head){
	 Link p,q;   //p,q�����ڵ�һǰһ��
	 Link node;  //nodeָ��ָ���´����Ľڵ�
	 node=(Link)malloc(sizeof(Node));
	 inputStudent(node);

	 q = head;
	 p = head->next;  //qָ��head����ĵ�һ����Ч�ڵ�
	 if(head->next==NULL)
		 //����Ϊ��ʱ
		head->next = node;
	 else {
		 //ѭ�����������е����нڵ�
		while(p != NULL){
			if (node->data.studentNo < p->data.studentNo){
				//���node�ڵ��ѧ�ű�p�ڵ��ѧ��С�������p��ǰ�棬��ɲ������ǰ�˳��ӳ���
				q->next = node;
				node->next = p;
				return true;
			}
			else{
				//���node�ڵ��ѧ�ű�p�ڵ��ѧ�Ŵ󣬼�������ƶ�ָ�루��Ȼ����pqһǰһ��
				q = p;
				p = p->next;

			}
		}
		//���û����ǰ�˳�ѭ������˵��֮ǰû�в��룬��ô��ǰnode�ڵ��ѧ�������ֵ����ʱ��������������
		q->next = node;

	}
	 return true;
}

bool deleteNode(Link head){
    // ���ո�����ѧ��ɾ��ѧ����¼�����ɾ���ɹ�����true�����û�ҵ�ѧ�ŷ���false

    //����Ҫ�����ѧ��
    	char no[NO_LENGTH];
	inputStudentNo("�޸�",no);

	return false;
}

bool queryNode(Link head){
    // ���ո�����ѧ�Ų�ѯѧ����¼�����ɾ���ɹ�����true�����û�ҵ�ѧ�ŷ���false

    //����Ҫ�����ѧ��
	char no[NO_LENGTH];
	inputStudentNo("�޸�",no);

	return false;
}

bool modifyNode(Link head){
    // ���ո�����ѧ���ҵ�ѧ����¼�ڵ㣬����޸ĳɹ�����true�����û�ҵ�ѧ�ŷ���false

    //����Ҫ�����ѧ��
	char no[NO_LENGTH];
	inputStudentNo("�޸�",no);

	return false;
}

int countNode(Link head){
	//ͳ��ѧ��������ɨ������ͳ�ƽڵ���������ؽڵ���
	Link p;
	int count = 0;
	p = head->next;

	//������
	return false;
}

void clearLink(Link head){
	Link q,p;
        //����������free���ɾ����������malloc����������еĽڵ�
}

int main() {
	int select;
    	int count;
	Link head;  // ��������

	//����headͷ��㣬�����������headָ��ͷ��㣬ͷ���data����û�����ݣ�������ڵ��������������
	head = (Link)malloc(sizeof(Node));
	head->next = NULL;

	while(1)
	{
		myMenu();
		printf("\n���������ѡ��(0-7):");  //��ʾ��ʾ��Ϣ
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			//����ѧ����¼
			if(addNode(head))
				printf("�ɹ�����һ��ѧ����¼��\n\n");
			break;
		case 2:
			//ɾ��ѧ����¼
			if(deleteNode(head))
				printf("�ɹ�ɾ��һ��ѧ����¼��\n\n");
			else
				printf("û���ҵ�Ҫɾ����ѧ���ڵ㡣\n\n");
			break;
		case 3:
			//��ѯѧ����¼
			if(queryNode(head))
				printf("�ɹ��ҵ�ѧ����¼��\n\n");
			else
				printf("û���ҵ�Ҫ��ѯ��ѧ���ڵ㡣\n\n");
			break;
		case 4:
			//�޸�ѧ����¼
			if(modifyNode(head))
				printf("�ɹ��޸�һ��ѧ����¼��\n\n");
			else
				printf("û���ҵ�Ҫ�޸ĵ�ѧ���ڵ㡣\n\n");
			break;
		case 5:
			//ͳ��ѧ������
			count = countNode(head);
			printf("ѧ������Ϊ��%d\n\n",count);
			break;
		case 6:
			//��ʾѧ����¼
			displayNode(head);
			break;
		case 7:
			//�˳�ǰ��������е����н��
            clearLink(head);
			return 0;
		default:
			printf("���벻��ȷ��Ӧ������0-7֮�������\n\n");
			break;
		}
	}
	return 0;
}
