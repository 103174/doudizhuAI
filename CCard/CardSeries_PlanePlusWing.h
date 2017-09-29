/**************************************************
*Module:
*    CardSeries_PlanePlusWing.h
*
*Description:
*	 飞机带翅膀：三顺+同数量的单牌（或同数量的对牌），
*    如444555+79或333444555+7799JJ        
          
*Author:
*	David.Zhu
*
*Date:
*	2007-2-12    
**************************************************/
#pragma  once

#include "CardSeries.h"

class CCardSeries_PlanePlusWing: public CCardSeries
{
public:
	CCardSeries_PlanePlusWing();
   ~CCardSeries_PlanePlusWing();

	virtual CCardSeries*  clone();
	virtual void		  sort();
   	virtual BYTE		  type();	

	virtual bool	operator <(CCardSeries &p);	//比较同类牌型的大小
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);

};
