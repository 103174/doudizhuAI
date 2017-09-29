#include "Card.h"
#include "CardSeries_SingleSeriesCard.h"
#include <algorithm>
using namespace std;


CCardSeries_SingleSeriesCard::CCardSeries_SingleSeriesCard()
{
}

CCardSeries_SingleSeriesCard::~CCardSeries_SingleSeriesCard()
{
}

BYTE    CCardSeries_SingleSeriesCard::type() 	
{
	m_CardType = CardSeries_Type_SingleSeries;
	return CardSeries_Type_SingleSeries;
}

void	CCardSeries_SingleSeriesCard::sort() 
{
     //先按大小排一次
	std::sort(m_Cards.begin(), m_Cards.end(), Lower);
}

bool	CCardSeries_SingleSeriesCard::operator <(CCardSeries &p)	
{
	   CCardSeries_SingleSeriesCard *pp = (CCardSeries_SingleSeriesCard*)&p;
	   sort();
	   p.sort();
	   return m_Cards[0] < pp->m_Cards[0];	   
}

bool	CCardSeries_SingleSeriesCard::operator >(CCardSeries &p)
{
	   CCardSeries_SingleSeriesCard *pp = (CCardSeries_SingleSeriesCard*)&p;
	   sort();
	   p.sort();
	   return m_Cards[0] > pp->m_Cards[0];	  
}

bool	CCardSeries_SingleSeriesCard::operator ==(CCardSeries &p)
{
	   CCardSeries_SingleSeriesCard *pp = (CCardSeries_SingleSeriesCard*)&p;
	   sort();
	   p.sort();
	   return m_Cards[0] == pp->m_Cards[0];		  
}

CCardSeries* CCardSeries_SingleSeriesCard::clone()
{
	CCardSeries_SingleSeriesCard *p = new(CCardSeries_SingleSeriesCard);
	p->m_CardType = this->m_CardType;
	for(int i=0; i < m_Cards.size(); i++)
	{
		p->m_Cards.push_back(m_Cards[i]);
	}
	p->bt_Base = this->bt_Base;
	return p;
}