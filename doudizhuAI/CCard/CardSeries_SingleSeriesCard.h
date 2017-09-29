/**************************************************
*		Module: CardSeries_SingleSeriesCard.h
*
*		Description:
*			���ƣ���˳
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
   	virtual BYTE    type() ;				//��ȡ����
	virtual bool	operator <(CCardSeries &p);	//�Ƚ�ͬ�����͵Ĵ�С
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);
	
	private:
		CCard   bt_Base; //������
};
