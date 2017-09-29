#include "CardSeries_SingleCard.h"
#include "Card.h"

CCardSeries_Single::CCardSeries_Single()
{

}

CCardSeries_Single::~CCardSeries_Single()
{
}

BYTE    CCardSeries_Single::type() 	
{
	m_CardType = CardSeries_Type_Single;
	return CardSeries_Type_Single;
}

bool	CCardSeries_Single::operator <(CCardSeries &p) 
{
	CCardSeries_Single *pp = (CCardSeries_Single*)&p;
	return m_Cards[0] < (*pp)[0];
}

bool	CCardSeries_Single::operator >(CCardSeries &p) 
{
	CCardSeries_Single *pp = (CCardSeries_Single*)&p;
	return m_Cards[0] > (*pp)[0];
}

bool	CCardSeries_Single::operator ==(CCardSeries &p) 
{
	CCardSeries_Single *pp = (CCardSeries_Single*)&p;
	return m_Cards[0] == (*pp)[0];
}

CCardSeries* CCardSeries_Single::clone()
{
	CCardSeries_Single *p = new(CCardSeries_Single);
	p->m_CardType = this->m_CardType;
	for(int i=0; i < m_Cards.size(); i++)
	{
		p->m_Cards.push_back(m_Cards[i]);
	}
	return p;
}