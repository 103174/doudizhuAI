#include "CardCompareImpl.h"
#include "CardSeries.h"
#include "Card.h"

#include <assert.h>

//初始化规则表,1表示大于，0表示可以比较，-1表示小于，-2表示不可比较
static char LordRuleTable[12][12]=
{
	{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},	//CardSeries_Type_Unknown
	{-2,-2, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1},	//CardSeries_Type_Rocket
	{-2,-1, 0, 1, 1, 1, 1, 1 ,1, 1, 1, 1},	//CardSeries_Type_Bomb
	{-2,-1,-1, 0,-2,-2,-2,-2,-2,-2,-2,-2},	//CardSeries_Type_Single
	{-2,-1,-1,-2, 0,-2,-2,-2,-2,-2,-2,-2},	//CardSeries_Type_Double
	{-2,-1,-1,-2,-2, 0,-2,-2,-2,-2,-2,-2},	//CardSeries_Type_TriCard
	{-2,-1,-1,-2,-2,-2, 0,-2,-2,-2,-2,-2},	//CardSeries_Type_TriPlusOne
	{-2,-1,-1,-2,-2,-2,-2, 0,-2,-2,-2,-2},	//CardSeries_Type_SingleSeries
	{-2,-1,-1,-2,-2,-2,-2,-2, 0,-2,-2,-2},	//CardSeries_Type_DoubleSeries
	{-2,-1,-1,-2,-2,-2,-2,-2,-2, 0,-2,-2},	//CardSeries_Type_TriSeries
	{-2,-1,-1,-2,-2,-2,-2,-2,-2,-2, 0,-2},	//CardSeries_Type_PlanPlusWing
	{-2,-1,-1,-2, 0,-2,-2,-2,-2,-2,-2, 0},	//CardSeries_Type_FourPlusTwo
};

//返回值定义：
//  1	：seriesA > seriesB
//	-1	：seriesA < seriesB
//	0	：seriesA = seriesB
//	-2	：两手牌无法比较，牌型不容许	
int	CCardCompareImpl::Exec(CCardSeries *seriesA,CCardSeries *seriesB)
{
	if(NULL==seriesA || NULL== seriesB)
		return -2;

	//确保牌型正确
	assert(seriesA->valid());
	assert(seriesB->valid());

	int  ret=-2;
	int  t1 = seriesA->type(); int t2 = seriesB->type();
	char compare=LordRuleTable[seriesA->type()][seriesB->type()];
	
	do
	{
		if(1==compare || -1==compare)
		{
			ret=(int)compare;
			break;
		}

		//同牌型的牌必须要总张数相同才能比较
		if(0==compare)
		{
			if(seriesA->size()==seriesB->size())
			{
				ret=(*seriesA)>(*seriesB)?1:((*seriesA)<(*seriesB))?-1:0;
			}else{
				ret  = -2;  //不可比较
			}
		}

	}while(0);

	return ret;
}