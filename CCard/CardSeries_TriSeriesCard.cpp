#include <algorithm>
using namespace std;
#include "Card.h"
#include "CardSeries_TriSeriesCard.h"

CCardSeries_TriSeriesCard::CCardSeries_TriSeriesCard()
{
}

CCardSeries_TriSeriesCard::~CCardSeries_TriSeriesCard()
{
}

BYTE    CCardSeries_TriSeriesCard::type() 	
{
	m_CardType = CardSeries_Type_DoubleSeries;
	return CardSeries_Type_DoubleSeries;
}

void	CCardSeries_TriSeriesCard::sort()
{
	std::sort(m_Cards.begin(), m_Cards.end(), Lower);
}

bool	CCardSeries_TriSeriesCard::operator <(CCardSeries&p)	
{
	CCardSeries_TriSeriesCard *pp = (CCardSeries_TriSeriesCard*)&p;
	sort();
	p.sort();
	return m_Cards[0] < pp->m_Cards[0] ;
}

bool	CCardSeries_TriSeriesCard::operator >(CCardSeries&p)
{
	CCardSeries_TriSeriesCard *pp = (CCardSeries_TriSeriesCard*)&p;
	sort();
	p.sort();
	return m_Cards[0] > pp->m_Cards[0] ;
}

bool	CCardSeries_TriSeriesCard::operator ==(CCardSeries &p)
{
	CCardSeries_TriSeriesCard *pp = (CCardSeries_TriSeriesCard*)&p;
	sort();
	p.sort();
	return m_Cards[0] == pp->m_Cards[0] ;
}

CCardSeries* CCardSeries_TriSeriesCard::clone()
{
	CCardSeries_TriSeriesCard *p = new(CCardSeries_TriSeriesCard);
	p->m_CardType = this->m_CardType;
	for(int i=0; i < m_Cards.size(); i++)
	{
		p->m_Cards.push_back(m_Cards[i]);
	}
	return p;
}