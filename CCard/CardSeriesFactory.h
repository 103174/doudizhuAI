/***************************************************
*	Module:	CardSeriesFactory.h
*
*	Description:
*			CardSeries的创建工厂，根据牌的CardSeries_Type_XXX
*		创建相应的对象。

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