#include "Card.h"
#include "CardSeries_TriPlusOneCard.h"
#include <algorithm>
using namespace std;


CCardSeries_TriPlusOneCard::CCardSeries_TriPlusOneCard()
{
}

CCardSeries_TriPlusOneCard::~CCardSeries_TriPlusOneCard()
{
}

BYTE  CCardSeries_TriPlusOneCard::type() 	
{
	m_CardType = CardSeries_Type_TriPlusOne;
	return CardSeries_Type_TriPlusOne;
}

void	CCardSeries_TriPlusOneCard::sort() 
{
	std::sort(m_Cards.begin(), m_Cards.end(), Lower);
	if(m_Cards[1] == m_Cards[2])
	{
		bt_Base = m_Cards[1];   
	}else{
		bt_Base = m_Cards[2];
	}
}

bool	CCardSeries_TriPlusOneCard::operator <(CCardSeries &p)	
{
	CCardSeries_TriPlusOneCard *pp = (CCardSeries_TriPlusOneCard*)&p;

	sort();
	p.sort();
	return bt_Base < pp->bt_Base ;
}

bool	CCardSeries_TriPlusOneCard::operator >(CCardSeries &p)
{
	CCardSeries_TriPlusOneCard *pp = (CCardSeries_TriPlusOneCard*)&p;
	sort();
	p.sort();
	return bt_Base > pp->bt_Base ;
}

bool	CCardSeries_TriPlusOneCard::operator ==(CCardSeries &p)
{
	CCardSeries_TriPlusOneCard *pp = (CCardSeries_TriPlusOneCard*)&p;
	sort();
	p.sort();
	return bt_Base == pp->bt_Base ;
}

CCardSeries* CCardSeries_TriPlusOneCard::clone()
{
	CCardSeries_TriPlusOneCard *p = new(CCardSeries_TriPlusOneCard);
	p->m_CardType = this->m_CardType;
	for(int i=0; i < m_Cards.size(); i++)
	{
		p->m_Cards.push_back(m_Cards[i]);
	}
	p->bt_Base = this->bt_Base;
	return p;
}