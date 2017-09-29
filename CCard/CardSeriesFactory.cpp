#include "CardSeriesFactory.h"

#include "CardSeries.h"
#include "CardSeries_FourPlusTwo.h"
#include "CardSeries_DoubleCard.h"
#include "CardSeries_DoubleSeriesCard.h"
#include "CardSeries_Bomb.h"
#include "CardSeries_PlanePlusWing.h"
#include "CardSeries_Rocket.h"
#include "CardSeries_SingleCard.h"
#include "CardSeries_SingleSeriesCard.h"
#include "CardSeries_TriCard.h"
#include "CardSeries_TriPlusOneCard.h"
#include "CardSeries_TriSeriesCard.h"


CCardSeries* CCardSeriesFactory::CreateCardSeries(unsigned char btCardSeriesType)
{
	CCardSeries *pCardSeries=NULL;

	switch(btCardSeriesType)
	{
	case CCardSeries::CardSeries_Type_Rocket:
		pCardSeries=new(CCardSeries_Rocket);
		break;
	case CCardSeries::CardSeries_Type_Bomb:
		pCardSeries=new(CCardSeries_Bomb);
		break;
	case CCardSeries::CardSeries_Type_Single:
		pCardSeries=new(CCardSeries_Single);
		break;
	case CCardSeries::CardSeries_Type_Double:
		pCardSeries=new(CCardSeries_Double);
		break;
	case CCardSeries::CardSeries_Type_TriCard:
		pCardSeries=new(CCardSeries_TriCard);
		break;
	case CCardSeries::CardSeries_Type_TriPlusOne:
		pCardSeries=new(CCardSeries_TriPlusOneCard);
		break;
	case CCardSeries::CardSeries_Type_SingleSeries:
		pCardSeries=new(CCardSeries_SingleSeriesCard);
		break;
	case CCardSeries::CardSeries_Type_DoubleSeries:
		pCardSeries=new(CCardSeries_DoubleSeriesCard);
		break;
	case CCardSeries::CardSeries_Type_TriSeries:
		pCardSeries=new(CCardSeries_TriSeriesCard);
		break;
	case CCardSeries::CardSeries_Type_PlanPlusWing:
		pCardSeries=new(CCardSeries_PlanePlusWing);
		break;
	case CCardSeries::CardSeries_Type_FourPlusTwo:
		pCardSeries=new(CCardSeries_FourPlusTwo);
		break;
	default:
		printf(0,0,"Failed to Create CardSeries,unknown card series type:%d",btCardSeriesType);
		break;
	}

	return pCardSeries;
}