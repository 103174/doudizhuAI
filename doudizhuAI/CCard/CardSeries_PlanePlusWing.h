/**************************************************
*Module:
*    CardSeries_PlanePlusWing.h
*
*Description:
*	 �ɻ��������˳+ͬ�����ĵ��ƣ���ͬ�����Ķ��ƣ���
*    ��444555+79��333444555+7799JJ        
          
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

	virtual bool	operator <(CCardSeries &p);	//�Ƚ�ͬ�����͵Ĵ�С
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);

};
