#include "CardSeries_FourPlusTwo.h"
#include <algorithm>
using namespace std;

CCardSeries_FourPlusTwo::CCardSeries_FourPlusTwo()
{
}

CCardSeries_FourPlusTwo::~CCardSeries_FourPlusTwo()
{
}

BYTE    CCardSeries_FourPlusTwo::type() 	
{
	m_CardType = CardSeries_Type_FourPlusTwo;
	return CardSeries_Type_FourPlusTwo;
}

void	CCardSeries_FourPlusTwo::sort()  
{
     //先按大小排一次
	std::sort(m_Cards.begin(), m_Cards.end(), Lower);
     
     //由于只有六张牌，并且有四张一样
     if(size() == 6)
     	{
           if( m_Cards[0] == m_Cards[1] && m_Cards[1] == m_Cards[2])
           {
             bt_Base = m_Cards[0];
           }else{
             bt_Base = m_Cards[2];	
		   }
     }
     
     if(size() == 8)
     {
           if( m_Cards[7] == m_Cards[6] && m_Cards[6] == m_Cards[5] && m_Cards[5] == m_Cards[4])
           {
             bt_Base = m_Cards[7];
           }else{
             bt_Base = m_Cards[0];	
          }	     		
     }  
}

bool	CCardSeries_FourPlusTwo::operator <(CCardSeries &p)	
{
	   CCardSeries_FourPlusTwo *pp = (CCardSeries_FourPlusTwo*)&p;
	   sort();
	   p.sort();
	   return bt_Base < pp->bt_Base;	   
}

bool	CCardSeries_FourPlusTwo::operator >(CCardSeries &p)
{
	   CCardSeries_FourPlusTwo *pp = (CCardSeries_FourPlusTwo*)&p;
	   sort();
	   p.sort();
	   return bt_Base > pp->bt_Base;  
}

bool	CCardSeries_FourPlusTwo::operator ==(CCardSeries &p)
{
	   CCardSeries_FourPlusTwo *pp = (CCardSeries_FourPlusTwo*)&p;
	   sort();
	   p.sort();
	   return bt_Base == pp->bt_Base;  
}

CCardSeries* CCardSeries_FourPlusTwo::clone()
{
	CCardSeries_FourPlusTwo *p = new(CCardSeries_FourPlusTwo);
	p->m_CardType = this->m_CardType;
	for(int i=0; i < m_Cards.size(); i++)
	{
		p->m_Cards.push_back(m_Cards[i]);
	}
	p->bt_Base = this->bt_Base;
	return p;
}