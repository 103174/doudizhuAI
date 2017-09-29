#include "Card.h"

CCard::CCard()
:m_btColor(4)
,m_btValue(0)
{
}

CCard::CCard(const CCard &card)
{
	m_btColor=card.Color();
	m_btValue=card.Value();
}

CCard::CCard(const char color,const char value)
{
	m_btColor=color;
	m_btValue=value;
}

CCard::CCard(const int index)
{
    //´óÐ¡Íõ
    if(index >= 52)
    {
        m_btColor=0;
        m_btValue=index-52+16;
    }
    else
    {
        m_btColor = index % 4 + 1;
        m_btValue = index / 4 + 3; 
    }
}


char CCard::LogicValue()
{
	char s = m_btValue;
   
    switch(s) {
    case 15:  //2
		s = 2;
    	break;
    case 14:  //A
		s = 1;
    	break;
    }

	return s;
}

CCard&	CCard::operator =(const CCard &card)
{
	m_btColor=card.Color();
	m_btValue=card.Value();

	return *this;
}

bool	CCard::operator < (const CCard &card)
{
	return m_btValue<card.Value()?true:false;
}

bool	CCard::operator > (const CCard &card)
{
	return m_btValue > card.Value()?true:false;
}

bool	CCard::operator ==(const CCard &card)
{
	return m_btValue == card.Value()?true:false;
}