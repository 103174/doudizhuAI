/**************************************************
*		Module: CardSeries_DoubleCard.h
*
*		Description:
*			���ƣ���ͬ��ֵ�������ƣ���÷��4+����4����ע�⣺����
*         �ȽϷ������ǻ�����ͬ����֮��ıȽϣ��ڵ���ǰ���뱣֤�Ƚ�
          ˫����������һ�µģ�����ᵼ�²���֪�ĺ����
*		Author:
*			David.Zhu
*		Date:
*			2007-2-12    
**************************************************/
#pragma  once

#include "CardSeries.h"

class CCardSeries_Double:public CCardSeries
{
public:
	CCardSeries_Double();
   ~CCardSeries_Double();
	virtual CCardSeries*    clone();
	virtual void	sort() ;
   	virtual BYTE    type() ;	//��ȡ����
	virtual bool	operator <(CCardSeries &p);	//�Ƚ�ͬ�����͵Ĵ�С
	virtual bool	operator >(CCardSeries &p);
	virtual bool	operator ==(CCardSeries &p);
};
