/**************************************************
*		Module: CardSeries_TriSeriesCard.h
*
*		Description:
*			对牌：连对，即：对三，对四，对五....
*         
          
*		Author:
*			David.Zhu
*		Date:
*			2007-2-12    
**************************************************/
#pragma   once
#include "CardSeries.h"

class CCardSeries_TriSeriesCard: public CCardSeries
{
public:
	CCardSeries_TriSeriesCard();
   ~CCardSeries_TriSeriesCard();
	virtual CCardSeries*    clone();
	virtual void	sort();
   	virtual BYTE    type();				//获取牌型
	virtual bool	operator <(CCardSeries &p);	//比较同类牌型的大小
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);
};
