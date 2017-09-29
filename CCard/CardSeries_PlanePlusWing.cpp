#include "Card.h"
#include "CardSeries_PlanePlusWing.h"
#include <iostream>
#include <algorithm>


CCardSeries_PlanePlusWing::CCardSeries_PlanePlusWing()
{
}


CCardSeries_PlanePlusWing::~CCardSeries_PlanePlusWing()
{
}


unsigned char  CCardSeries_PlanePlusWing::type() 	
{
	return CardSeries_Type_PlanPlusWing;
}


void  CCardSeries_PlanePlusWing::sort()  
{
	//找出三顺,并排序
	char		btVec[18]={0};
	const char  btSize=m_Cards.size();
	
	for(int n=0;n<btSize;++n)
	{
		btVec[m_Cards[n].Value()]+=1;
	}
	
	//模糊排序一次,将非三顺的牌放到末尾
	CCard   tempCard;
	char	btBegin=0;
	char	btEnd  =btSize-1;

	while(btBegin<btEnd)
	{
		while(3==btVec[m_Cards[btBegin].Value()])
		{
			++btBegin;
			continue;
		}

		while(3!=btVec[m_Cards[btEnd].Value()])
		{
			--btEnd;
			continue;
		}

		if(btEnd<=btBegin)
		{
			break;
		}

		//Exchange btBegin<-->btEnd
		tempCard=m_Cards[btBegin];
		m_Cards[btBegin]=m_Cards[btEnd];
		m_Cards[btEnd]=tempCard;	
		
		++btBegin;--btEnd;
	}
	
    //先按大小排一次
	std::sort(m_Cards.begin(),m_Cards.begin()+btBegin,Lower);	
}

CCardSeries* CCardSeries_PlanePlusWing::clone()
{
	CCardSeries_PlanePlusWing *p = new CCardSeries_PlanePlusWing();

	for(int i=0; i < m_Cards.size(); i++)
	{
		p->Card(i)=m_Cards[i];
	}

	return p;
}

bool CCardSeries_PlanePlusWing::operator <(CCardSeries &p)	
{
	CCardSeries_PlanePlusWing *pp = (CCardSeries_PlanePlusWing*)&p;
	sort();
	p.sort();
	return m_Cards[0] < pp->m_Cards[0] ;
}

bool CCardSeries_PlanePlusWing::operator >(CCardSeries &p)	
{
	
	CCardSeries_PlanePlusWing *pp = (CCardSeries_PlanePlusWing*)&p;
	sort();
	p.sort();
	return m_Cards[0] > pp->m_Cards[0] ;
	
	return true;
}

bool CCardSeries_PlanePlusWing::operator ==(CCardSeries &p)	
{
	CCardSeries_PlanePlusWing *pp = (CCardSeries_PlanePlusWing*)&p;
	sort();
	p.sort();
	return m_Cards[0] == pp->m_Cards[0] ;
}
