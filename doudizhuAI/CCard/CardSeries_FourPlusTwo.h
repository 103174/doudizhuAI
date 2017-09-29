/**************************************************
*		Module: CardSeries_FourPlusTwo.h
*
*		Description:
*			对牌：连对，即：对三，对四，对五....
*         
          
*		Author:
*			David.Zhu
*		Date:
*			2007-2-12    
**************************************************/
#pragma  once
#include "Card.h"
#include "CardSeries.h"

class CCardSeries_FourPlusTwo: public CCardSeries
{
public:
	CCardSeries_FourPlusTwo();
   ~CCardSeries_FourPlusTwo();
	virtual CCardSeries*    clone();
	virtual void	sort()  ;
   	virtual BYTE    type() ;				//获取牌型
	virtual bool	operator <(CCardSeries &p);	//比较同类牌型的大小
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries&p);
	
	private:
		CCard   bt_Base; //四张牌
};
