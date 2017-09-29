/**************************************************
*		Module: CardSeries_TriPlusOneCard.h
*
*		Description:
*			���ƣ����ԣ��������������ģ�����....
*         
          
*		Author:
*			David.Zhu
*		Date:
*			2007-2-12    
**************************************************/
#pragma once
#include "CardSeries.h"

class CCardSeries_TriPlusOneCard: public CCardSeries
{
public:
	CCardSeries_TriPlusOneCard();
   ~CCardSeries_TriPlusOneCard();
	virtual CCardSeries*    clone();
	virtual void	sort()  ;
   	virtual BYTE    type() ;				//��ȡ����
	virtual bool	operator <(CCardSeries &p);	//�Ƚ�ͬ�����͵Ĵ�С
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);
public:
	CCard bt_Base;
};