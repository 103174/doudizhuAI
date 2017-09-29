/*************************************************************
*	Module:	CardCompareImpl.h
*
*	Description:
*		牌型的大小比较算法封装并提供了斗地主的牌型的大小比较算法
*	实现。

*	Author:
		David.Zhu
*	Date:
*		2007-2-12
*************************************************************/
#ifndef __INC_CARD_COMPARE_IMPL_DEF_H__
#define __INC_CARD_COMPARE_IMPL_DEF_H__

class CCardSeries;
class ICardCompare
{
public:
	virtual ~ICardCompare(){};

	//返回值定义：
	//  1	：seriesA > seriesB
	//	-1	：seriesA < seriesB
	//	0	：seriesA = seriesB
	//	-2	：两手牌无法比较，牌型不容许
	virtual int	Exec(CCardSeries *seriesA,CCardSeries *seriesB)=0;
};


class CCardCompareImpl:public ICardCompare
{
public:
	 CCardCompareImpl(){};
	~CCardCompareImpl(){};
	
	virtual int	Exec(CCardSeries *seriesA,CCardSeries *seriesB);
};
#endif //__INC_CARD_COMPARE_IMPL_DEF_H__