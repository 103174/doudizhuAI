/***************************************************
*	Module:	CardSeriesFactory.h
*
*	Description:
*			CardSeries�Ĵ��������������Ƶ�CardSeries_Type_XXX
*		������Ӧ�Ķ���

*	Author:
			David.Zhu

*	Date:
			2007-2-14
****************************************************/
#ifndef __INC_CARDSERIES_FACTORY_DEF_H__
#define __INC_CARDSERIES_FACTORY_DEF_H__
#include "Utils.h"
//pre-declaration
class CCardSeries;



class CCardSeriesFactory
{
public:
	 CCardSeriesFactory(){};
	~CCardSeriesFactory(){};

	CCardSeries*	CreateCardSeries(unsigned char btCardSeriesType);

	DECLARE_SINGLETON(CCardSeriesFactory);

	
};

#endif //__INC_CARDSERIES_FACTORY_DEF_H__