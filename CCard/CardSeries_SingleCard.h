#ifndef __INC_CARDSERIES_SINGLE_CARD_DEF_H__
#define __INC_CARDSERIES_SINGLE_CARD_DEF_H__

#include "CardSeries.h"

class CCardSeries_Single:public CCardSeries
{
public:
	 CCardSeries_Single();
	~CCardSeries_Single();
	virtual CCardSeries*    clone();
	virtual void	sort(){};
	virtual BYTE    type()  ;				//��ȡ����
	virtual bool	operator <(CCardSeries &p) ;	//�Ƚ�ͬ�����͵Ĵ�С
	virtual bool	operator >(CCardSeries &p) ;
	virtual bool	operator ==(CCardSeries &p) ;
};

#endif //__INC_CARDSERIES_SINGLE_CARD_DEF_H__