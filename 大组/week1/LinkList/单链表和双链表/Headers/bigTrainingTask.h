#pragma once
typedef struct singleNode {
	char data;
	struct singleNode* next;
}singleNode;       //������ṹ
typedef struct doubleNode {
	char data;
	struct doubleNode* next;
	struct doubleNode* previous;
}doubleNode;       //˫����ṹ
void displayMenu(char menu[][27], int size);        //���ڴ�ӡ�˵��ĺ���,size����ȷ����ӡ����
singleNode* singleNodeGeneration();                 //���ڹ���������ĺ���
singleNode* singleNodeDestroy();					//�������ٵ�����ĺ���
int nodeDisplay(int flag);							//���ڴ�ӡ�������ݵĺ���,flag���ھ�����ӡ�������˫����,���ؽڵ����
singleNode* singleNodeInsert();						//���ڲ�����ĺ���,��ѡ���м����,β������,ͷ������
singleNode* singleNodeDelete();						//����ɾ��������ĳ�ڵ�
singleNode* singleNodeSearch();						//���ڵ���������Ƿ����ĳ���ݵĺ���
singleNode* parityExchange();						//������ż�ڵ�Ի��ĺ���
singleNode* middleSearch();							//������Ѱ�м�ڵ�,�Ҵ�ӡ�м�ڵ�����ĺ���
void circleJudge();                                 //�����ж��Ƿ�Ϊѭ������ĺ���,����β��ͷ������(�������������)
singleNode* singleNodeReversal();                   //���ڵ�����ת(�ǵݹ�)
singleNode* singleNodeReversalRecursion(singleNode* Head); //���ڵ�����ת(�ݹ�)
void singleLinkedList();                            //���ڵ�����˵���������
doubleNode* doubleNodeGeneration();                 //����˫������������
doubleNode* doubleNodeDestroy();                    //����˫����������
doubleNode* doubleNodeInsert();						//����˫���������
doubleNode* doubleNodeDelete();						//����˫������ڵ�ɾ��
doubleNode* doubleNodeSearch();						//����˫������Ľڵ��ѯ
void doubleLinkedList();							//����˫������˵���������