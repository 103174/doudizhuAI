/**************************************************
*		Module: CardSeries_TriCard.h
*
*		Description:
*			对牌：连对，即：对三，对四，对五....
*         
          
*		Author:
*			David.Zhu
*		Date:
*			2007-2-12    
**************************************************/
#pragma once
#include "CardSeries.h"

class CCardSeries_TriCard: public CCardSeries
{
public:
	CCardSeries_TriCard();
   ~CCardSeries_TriCard();
	virtual CCardSeries*    clone();
	virtual void	sort() ;
   	virtual BYTE    type() ;				//获取牌型
	virtual bool	operator <(CCardSeries &p);	//比较同类牌型的大小
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);
};