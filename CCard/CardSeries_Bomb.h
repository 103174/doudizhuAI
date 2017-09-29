/**************************************************
*		Module: CardSeries_Bomb.h
*
*		Description:
*			对牌：相同数值的四张张牌（如梅花4+方块4）。注意：下述
*         比较方法都是基于相同牌型之间的比较，在调用前必须保证比较
          双方的牌型是一致的，否则会导致不可知的后果。
*		Author:
*			David.Zhu
*		Date:
*			2007-2-12    
**************************************************/
#pragma   once
#include "CardSeries.h"

class CCardSeries_Bomb:public CCardSeries
{
public:
	CCardSeries_Bomb();
   ~CCardSeries_Bomb();
public:
	virtual CCardSeries*    clone();
	virtual void	sort()  ;
   	virtual BYTE    type()  ;				//获取牌型
	virtual bool	operator <(CCardSeries &p);	//比较同类牌型的大小
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);
};
