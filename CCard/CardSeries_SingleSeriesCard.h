/**************************************************
*		Module: CardSeries_SingleSeriesCard.h
*
*		Description:
*			对牌：单顺
*         
          
*		Author:
*			David.Zhu
*		Date:
*			2007-2-12    
**************************************************/
#pragma  once
#include "CardSeries.h"

class CCardSeries_SingleSeriesCard: public CCardSeries
{
public:
	CCardSeries_SingleSeriesCard();
   ~CCardSeries_SingleSeriesCard();
	virtual CCardSeries*    clone();
	virtual void	sort();
   	virtual BYTE    type() ;				//获取牌型
	virtual bool	operator <(CCardSeries &p);	//比较同类牌型的大小
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);
	
	private:
		CCard   bt_Base; //四张牌
};
