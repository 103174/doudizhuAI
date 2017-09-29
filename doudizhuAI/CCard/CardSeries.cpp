#include "CardSeries.h"
#include "Card.h"


CCardSeries::CCardSeries()
{
	m_CardType = CardSeries_Type_Unknown;
}

CCardSeries::~CCardSeries()
{
	
}

CCardSeries::CCardSeries(CCardSeries &CardSeries)
{
	m_CardType = CardSeries.type();

	for(int n=0;n<CardSeries.size();++n)
	{
		m_Cards.push_back(CardSeries[n]);
	}
}

bool CCardSeries::Init(CCard *pCards, int nSize)
{
	if(nSize < 0 || pCards == NULL)
		return false;
	for(int i=0; i< nSize; i++)
	{
        m_Cards.push_back(pCards[i]);
	}
	return true;
}

CCard&  CCardSeries::Card(int index)
{
    return  m_Cards[index];
}

CCard&	CCardSeries::operator [](int index)	
{
	return  m_Cards[index];
}

CCardSeries&	CCardSeries::operator = ( CCardSeries &CardSeries)
{
	m_Cards.clear();
	for(int n=0;n<CardSeries.size();++n)
	{
		m_Cards[n]=CardSeries[n];
	}

	return *this;	
}

bool	CCardSeries::valid() const
{
	return true;
}


bool Lower(CCard &c1,CCard &c2)
{
	   return c1 < c2;	
}