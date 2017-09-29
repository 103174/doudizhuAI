#include "CardSeries.h"
#include "CardSeriesIdentifierImpl.h"
#include "Card.h"
#include <ASSERT.H>
#include <algorithm>
using namespace std;


char CCardSeriesIdentifierImpl::Exec(CCard *pCard,int size)
{
	//计算特征向量
	char  btVec[18]={0};
	for(int n=0;n<size;++n)
	{
		btVec[pCard[n].Value()]+=1;
	}

	WORD value		=CalcVectorModule(btVec,18);
	char btModule	=LOWORD(value);		//向量的模
	char btPos		=HIWORD(value);	//最大模的位置

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
			//判断是否是火箭
			if(btVec[16]==1 && btVec[17]==1)
			{
				type=CCardSeries::CardSeries_Type_Rocket;
				break;
			}

			//判断是否为对牌
			if(2==btModule)
			{
				type=CCardSeries::CardSeries_Type_Double;
				break;
			}
			
			//非法牌
			break;
		}

		
		if(3==size)
		{
			//判断是否为三张牌
			if(3==btModule)
			{
				type=CCardSeries::CardSeries_Type_TriCard;
				break;
			}

			//非法牌
			break;
		}

		if(4==size)
		{
			//判断是否是炸弹
			if(4==btModule)
			{
				type=CCardSeries::CardSeries_Type_Bomb;
				break;
			}

			//判断是否是三带一（带单张）
			if(3==btModule)
			{
				type=CCardSeries::CardSeries_Type_TriPlusOne;
				break;
			}
			
			//非法牌
			break;
		}
		
		//判断四带二
		if(4==btModule)
		{
			if(6==size)
			{
				//四带两个单张
				type=CCardSeries::CardSeries_Type_FourPlusTwo;
				break;
			}

			if(8==size)
			{
				//四带两对
				if(IsVectorFeature(btVec,18,2,2))
				{
					type=CCardSeries::CardSeries_Type_FourPlusTwo;
				}
				
				break;
			}

			break;
		}

		//判断单顺
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

		//判断双顺
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
			//判断三带一对
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

			//判断三顺	
			if(size==len*3)
			{
				type=CCardSeries::CardSeries_Type_TriSeries;
				break;
			}

			//判断飞机带翅膀
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
	获取向量中数值最大的元素的值
[Parameters]
	[IN]char *pVec
		input vector
	[IN]int size
		count of elements in input vector
[Return Value]
	向量中数值最大的元素的值
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
	获取连续牌的最大长度
[Parameters]
	[IN]char  *pVec
		特征向量
	[IN]int size
		特征向量的长度
	[IN]int threshold
		连续牌要求的最小值。（单顺为1，双顺为2，三顺为3）
[Return Value]
	连续牌的最大长度
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
	寻找指定的特征向量中是否出现指定牌（单牌或对牌）。
[Parameters]
	[IN]char  *pVec
		特征向量
	[IN]int size
		特征向量的长度
	[IN]int threshold
		连续牌要求的最小值。（单顺为1，双顺为2，三顺为3）
	[IN]int cnt
		指定牌出现的次数
[Return Value]
	出现指定牌指定次数，返回true；否则返回false.
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