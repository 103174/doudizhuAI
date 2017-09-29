#include "CardSeries_DoubleSeriesCard.h"
#include <algorithm>
#include "Card.h"

CCardSeries_DoubleSeriesCard::CCardSeries_DoubleSeriesCard()
{
}

CCardSeries_DoubleSeriesCard::~CCardSeries_DoubleSeriesCard()
{
}

BYTE    CCardSeries_DoubleSeriesCard::type() 	
{
	m_CardType = CardSeries_Type_DoubleSeries;
	return CardSeries_Type_DoubleSeries;
}

void	CCardSeries_DoubleSeriesCard::sort()  
{
	std::sort(m_Cards.begin(), m_Cards.end(), Lower);
}

bool	CCardSeries_DoubleSeriesCard::operator <(CCardSeries &p)	
{
	CCardSeries_DoubleSeriesCard *pp = (CCardSeries_DoubleSeriesCard*)&p;
	sort();
	p.sort();
	return m_Cards[0] < pp->m_Cards[0] ;
}

bool	CCardSeries_DoubleSeriesCard::operator >(CCardSeries &p)
{
	CCardSeries_DoubleSeriesCard *pp = (CCardSeries_DoubleSeriesCard*)&p;
	sort();
	p.sort();
	return m_Cards[0] > pp->m_Cards[0] ;
}

bool	CCardSeries_DoubleSeriesCard::operator ==(CCardSeries &p)
{
	CCardSeries_DoubleSeriesCard *pp = (CCardSeries_DoubleSeriesCard*)&p;
	sort();
	p.sort();
	return m_Cards[0] == pp->m_Cards[0] ;
}

CCardSeries* CCardSeries_DoubleSeriesCard::clone()
{
	CCardSeries_DoubleSeriesCard *p = new(CCardSeries_DoubleSeriesCard);
	p->m_CardType = this->m_CardType;
	for(int i=0; i < m_Cards.size(); i++)
	{
		p->m_Cards.push_back(m_Cards[i]);
	}
	return p;
}