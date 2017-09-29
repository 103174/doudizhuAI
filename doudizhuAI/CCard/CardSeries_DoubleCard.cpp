#include "CardSeries_DoubleCard.h"
#include "Card.h"

CCardSeries_Double::CCardSeries_Double()
{
}

CCardSeries_Double::~CCardSeries_Double()
{
}

BYTE    CCardSeries_Double::type() 	
{
	m_CardType = CardSeries_Type_Double;
	return CardSeries_Type_Double;
}

void	CCardSeries_Double::sort()  
{
    CCard tmp = m_Cards[0];
    
	CCard c1,c2;
	c1 = m_Cards[0];
	c2 = m_Cards[1];

	if( c1 >c2)
    {
       m_Cards[0] = c2;
       m_Cards[1]=  c1;		
    }
}
bool	CCardSeries_Double::operator <(CCardSeries &p)	
{
	CCardSeries_Double *pp = (CCardSeries_Double*)&p;
	sort();
	p.sort();
	return m_Cards[0] < pp->m_Cards[0] ;
}
bool	CCardSeries_Double::operator >(CCardSeries &p)
{
	CCardSeries_Double *pp = (CCardSeries_Double*)&p;
	sort();
	p.sort();
	return m_Cards[0] > pp->m_Cards[0] ;
}
bool	CCardSeries_Double::operator ==(CCardSeries &p)
{
	CCardSeries_Double *pp = (CCardSeries_Double*)&p;
	sort();
	p.sort();
	return m_Cards[0] == pp->m_Cards[0] ;
}

CCardSeries* CCardSeries_Double::clone()
{
	CCardSeries_Double *p = new(CCardSeries_Double);
	p->m_CardType = this->m_CardType;
	for(int i=0; i < m_Cards.size(); i++)
	{
		p->m_Cards.push_back(m_Cards[i]);
	}
	return p;
}