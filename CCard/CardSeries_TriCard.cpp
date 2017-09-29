#include "CardSeries_TriCard.h"
#include "Card.h"
#include <algorithm>
using namespace std;

CCardSeries_TriCard::CCardSeries_TriCard()
{
}

CCardSeries_TriCard::~CCardSeries_TriCard()
{
}

BYTE    CCardSeries_TriCard::type() 	
{
	m_CardType = CardSeries_Type_TriCard;
	return CardSeries_Type_TriCard;
}

void	CCardSeries_TriCard::sort()
{
	std::sort(m_Cards.begin(), m_Cards.end(), Lower);
}

bool	CCardSeries_TriCard::operator <(CCardSeries &p)	
{
	CCardSeries_TriCard *pp = (CCardSeries_TriCard*)&p;
	sort();
	p.sort();
	return m_Cards[0] < pp->m_Cards[0] ;
}

bool	CCardSeries_TriCard::operator >(CCardSeries &p)
{
	CCardSeries_TriCard *pp = (CCardSeries_TriCard*)&p;
	sort();
	p.sort();
	return m_Cards[0] > pp->m_Cards[0] ;
}

bool	CCardSeries_TriCard::operator ==(CCardSeries &p)
{
	CCardSeries_TriCard *pp = (CCardSeries_TriCard*)&p;
	sort();
	p.sort();
	return m_Cards[0] == pp->m_Cards[0] ;
}

CCardSeries* CCardSeries_TriCard::clone()
{
	CCardSeries_TriCard *p = new(CCardSeries_TriCard);
	p->m_CardType = this->m_CardType;
	for(int i=0; i < m_Cards.size(); i++)
	{
		p->m_Cards.push_back(m_Cards[i]);
	}
	return p;
}