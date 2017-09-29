#include "CardSeries.h"
#include "CardSeriesIdentifierImpl.h"
#include "Card.h"
#include <ASSERT.H>
#include <algorithm>
using namespace std;


char CCardSeriesIdentifierImpl::Exec(CCard *pCard,int size)
{
	//������������
	char  btVec[18]={0};
	for(int n=0;n<size;++n)
	{
		btVec[pCard[n].Value()]+=1;
	}

	WORD value		=CalcVectorModule(btVec,18);
	char btModule	=LOWORD(value);		//������ģ
	char btPos		=HIWORD(value);	//���ģ��λ��

	char type=CCardSeries::CardSeries_Type_Unknown;
	do
	{
		if(1==size)
		{
			type=CCardSeries::CardSeries_Type_Single;
			break;
		}

		if(2==size)
		{
			//�ж��Ƿ��ǻ��
			if(btVec[16]==1 && btVec[17]==1)
			{
				type=CCardSeries::CardSeries_Type_Rocket;
				break;
			}

			//�ж��Ƿ�Ϊ����
			if(2==btModule)
			{
				type=CCardSeries::CardSeries_Type_Double;
				break;
			}
			
			//�Ƿ���
			break;
		}

		
		if(3==size)
		{
			//�ж��Ƿ�Ϊ������
			if(3==btModule)
			{
				type=CCardSeries::CardSeries_Type_TriCard;
				break;
			}

			//�Ƿ���
			break;
		}

		if(4==size)
		{
			//�ж��Ƿ���ը��
			if(4==btModule)
			{
				type=CCardSeries::CardSeries_Type_Bomb;
				break;
			}

			//�ж��Ƿ�������һ�������ţ�
			if(3==btModule)
			{
				type=CCardSeries::CardSeries_Type_TriPlusOne;
				break;
			}
			
			//�Ƿ���
			break;
		}
		
		//�ж��Ĵ���
		if(4==btModule)
		{
			if(6==size)
			{
				//�Ĵ���������
				type=CCardSeries::CardSeries_Type_FourPlusTwo;
				break;
			}

			if(8==size)
			{
				//�Ĵ�����
				if(IsVectorFeature(btVec,18,2,2))
				{
					type=CCardSeries::CardSeries_Type_FourPlusTwo;
				}
				
				break;
			}

			break;
		}

		//�жϵ�˳
		if(1==btModule)
		{
			int len=GetSeriesLength(&btVec[3],13,1);
			if(len>=5 && len==size)
			{
				type=CCardSeries::CardSeries_Type_SingleSeries;
				break;
			}

			break;
		}

		//�ж�˫˳
		if(2==btModule)
		{
			int len=GetSeriesLength(&btVec[3],13,2);
			if(len>=3 && 2*len==size)
			{
				type=CCardSeries::CardSeries_Type_DoubleSeries;
				break;
			}

			break;
		}
		
		if(3==btModule)
		{
			//�ж�����һ��
			if(size==5)
			{
				if(IsVectorFeature(btVec,18,2,1))
				{
					type=CCardSeries::CardSeries_Type_TriPlusOne;
					break;
				}

				break;
			}

			
			int len=GetSeriesLength(&btVec[3],13,3);
			if(len<2)
			{
				break;
			}

			//�ж���˳	
			if(size==len*3)
			{
				type=CCardSeries::CardSeries_Type_TriSeries;
				break;
			}

			//�жϷɻ������
			if(size==len*4 && IsVectorFeature(btVec,18,1,len))
			{
				type=CCardSeries::CardSeries_Type_PlanPlusWing;
				break;
			}

			if(size==len*5 && IsVectorFeature(btVec,18,2,len))
			{
				type=CCardSeries::CardSeries_Type_PlanPlusWing;
				break;
			}

			break;			
		}

	}while(0);

	return type;
}

/*++
[Description]
	��ȡ��������ֵ����Ԫ�ص�ֵ
[Parameters]
	[IN]char *pVec
		input vector
	[IN]int size
		count of elements in input vector
[Return Value]
	��������ֵ����Ԫ�ص�ֵ
--*/
 WORD	CCardSeriesIdentifierImpl::CalcVectorModule(char *pVec,int size)
 {
	 char btModule=0;
	 char btPos=0;

	 for(int n=0;n<size;++n)
	 {
		if(pVec[n]>btModule)
		 {
			btModule=pVec[n];
			btPos=n;
		 }
	 }

	assert(btModule<5);

	 return MAKEWORD(btModule,btPos);
 }


/*++
[Description]
	��ȡ�����Ƶ���󳤶�
[Parameters]
	[IN]char  *pVec
		��������
	[IN]int size
		���������ĳ���
	[IN]int threshold
		������Ҫ�����Сֵ������˳Ϊ1��˫˳Ϊ2����˳Ϊ3��
[Return Value]
	�����Ƶ���󳤶�
--*/
char	CCardSeriesIdentifierImpl::GetSeriesLength(char *pVec,int size,int threshold)
{
	 char nMaxLen	=0;
	 char len		=0;

	 for(int n=0;n<size;++n)
	 {
		if(pVec[n]>=threshold)
		{
			++len;

			if(len>nMaxLen)
			{
				nMaxLen=len;
			}
		}
		else if(0!=len)
		{
			len=0;
		}
	 }

	 return nMaxLen;
 }

/*++
[Description]
	Ѱ��ָ���������������Ƿ����ָ���ƣ����ƻ���ƣ���
[Parameters]
	[IN]char  *pVec
		��������
	[IN]int size
		���������ĳ���
	[IN]int threshold
		������Ҫ�����Сֵ������˳Ϊ1��˫˳Ϊ2����˳Ϊ3��
	[IN]int cnt
		ָ���Ƴ��ֵĴ���
[Return Value]
	����ָ����ָ������������true�����򷵻�false.
--*/
bool	CCardSeriesIdentifierImpl::IsVectorFeature(char *pVec,int size,int threshold,int cnt)
{
	int counter=0;

	for(int n=0;n<size;++n)
	{
		if(pVec[n]==threshold)
		{
			++counter;
		}
	}

	return (counter==cnt)?true:false;
}