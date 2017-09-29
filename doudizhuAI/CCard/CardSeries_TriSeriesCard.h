/**************************************************
*		Module: CardSeries_TriSeriesCard.h
*
*		Description:
*			���ƣ����ԣ��������������ģ�����....
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
   	virtual BYTE    type();				//��ȡ����
	virtual bool	operator <(CCardSeries &p);	//�Ƚ�ͬ�����͵Ĵ�С
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);
};
