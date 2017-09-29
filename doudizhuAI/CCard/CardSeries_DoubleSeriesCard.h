/**************************************************
*		Module: CardSeries_DoubleSeriesCard.h
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

class CCardSeries_DoubleSeriesCard: public CCardSeries
{
public:
	CCardSeries_DoubleSeriesCard();
   ~CCardSeries_DoubleSeriesCard();
	virtual CCardSeries*    clone();
	virtual void	sort()  ;
   	virtual BYTE    type() ;				//获取牌型
	virtual bool	operator <(CCardSeries &p);	//比较同类牌型的大小
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);
};
