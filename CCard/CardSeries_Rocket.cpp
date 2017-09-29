#include "CardSeries_Rocket.h"
#include "Card.h"
CCardSeries_Rocket::CCardSeries_Rocket()
{
}

CCardSeries_Rocket::~CCardSeries_Rocket()
{
}

BYTE CCardSeries_Rocket::type() 	
{
	m_CardType = CardSeries_Type_Rocket;
	return CardSeries_Type_Rocket;
}

void CCardSeries_Rocket::sort()
{
  
}

bool	CCardSeries_Rocket::operator <(CCardSeries &p)	
{
   return false;  
}

bool	CCardSeries_Rocket::operator >(CCardSeries &p)
{
   return false;	 
}

bool	CCardSeries_Rocket::operator ==(CCardSeries &p)
{
		return false;  
}

CCardSeries* CCardSeries_Rocket::clone()
{
	CCardSeries_Rocket *p = new(CCardSeries_Rocket);
	p->m_CardType = this->m_CardType;
	for(int i=0; i < m_Cards.size(); i++)
	{
		p->m_Cards.push_back(m_Cards[i]);
	}
	return p;
}