#include "CardSeries_Bomb.h"
#include "Card.h"
CCardSeries_Bomb::CCardSeries_Bomb()
{
}

CCardSeries_Bomb::~CCardSeries_Bomb()
{
}

BYTE    CCardSeries_Bomb::type() 	
{
	m_CardType = CardSeries_Type_Bomb;
	return CardSeries_Type_Bomb;
}

void	CCardSeries_Bomb::sort()  
{

}
bool	CCardSeries_Bomb::operator <(CCardSeries &p)	
{
	CCardSeries_Bomb *pp = (CCardSeries_Bomb*)&p;
	sort();
	p.sort();
	return m_Cards[0] < pp->m_Cards[0] ;
}

bool	CCardSeries_Bomb::operator >(CCardSeries &p)
{
	CCardSeries_Bomb *pp = (CCardSeries_Bomb*)&p;
	sort();
	p.sort();
	return m_Cards[0] > pp->m_Cards[0] ;
}
bool	CCardSeries_Bomb::operator ==(CCardSeries &p)
{
	CCardSeries_Bomb *pp = (CCardSeries_Bomb*)&p;
	sort();
	p.sort();
	return m_Cards[0] == pp->m_Cards[0] ;
}

CCardSeries* CCardSeries_Bomb::clone()
{
	CCardSeries_Bomb *p = new(CCardSeries_Bomb);
	p->m_CardType = this->m_CardType;
	for(int i=0; i < m_Cards.size(); i++)
	{
		p->m_Cards.push_back(m_Cards[i]);
	}
	return p;
}