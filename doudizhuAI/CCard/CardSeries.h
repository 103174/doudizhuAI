/*****************************************************
*
*		Module: CardSeries.h

*		Description:
*				斗地主中牌型的封装。这些牌型一般
         是由一张或几张牌组合而成的。

*		Author:
*				David.Zhu

*		Date:
*				2007-2-11
******************************************************/
#ifndef __INC_CARD_SERIES_DEF_H__
#define __INC_CARD_SERIES_DEF_H__

#include <vector>
#include "CardCompareImpl.h"
#include "Card.h"
using namespace std;

//Forward declaration
class CCard;

typedef unsigned char BYTE;

class CCardSeries
{
public:
	CCardSeries();
	CCardSeries(CCardSeries &series);

	virtual ~CCardSeries();
	
	enum
	{
		CardSeries_Type_Unknown		=0x00,	//未知牌型
		CardSeries_Type_Rocket		=0x01,	//火箭：双王（大王和小王），最大的牌
		CardSeries_Type_Bomb		=0x02,	//炸弹：四张同数值牌（如四个7）
		CardSeries_Type_Single		=0x03,	//单张：（如红桃5）
		CardSeries_Type_Double		=0x04,	//对牌：相同数值的两张牌（如梅花4+方块4）
		CardSeries_Type_TriCard		=0x05,	//三张牌：数值相同的三张牌（如三个J）
		CardSeries_Type_TriPlusOne	=0x06,	//三带一：数值相同的三张牌+一张单牌或一对牌
		CardSeries_Type_SingleSeries=0x07,	//单顺：五张或更多的连续单牌（如34567或78910JQK)。但不包括2点和双王
		CardSeries_Type_DoubleSeries=0x08,  //双顺：三对或更多的连续对牌（如334455或7788991010JJ），但不包括2点和双王
		CardSeries_Type_TriSeries	=0x09,	//三顺：两个或更多的连续三张牌（如333444或555666777），但不包括2点和双王
		CardSeries_Type_PlanPlusWing=0x0A,	//飞机带翅膀：三顺+同数量的单牌（或同数量的对牌），如444555+79或333444555+7799JJ
		CardSeries_Type_FourPlusTwo	=0x0B	//四带二：四张牌+两手牌（注意：四带二不是炸弹）如5555+3+8或4444+55+77
	};

	bool   Init(CCard *pCards, int nSize); //初始化一手牌

	bool			valid() const;		//判断牌型的是否正确
	inline int		size()  const{
		return m_Cards.size();
	}

	CCard&			Card(int index);
	CCard&	operator [](int index) ;	
	CCardSeries&	operator = ( CCardSeries &CardSeries);

	virtual CCardSeries*    clone() = 0;	//牌型的克隆创建
	virtual void	sort() = 0;	 //对牌进行排序

	
	virtual BYTE type()
	{
		return m_CardType;
	}
	
	virtual bool	operator <(CCardSeries &p) = 0;	//比较同类牌型的大小
	virtual bool	operator >(CCardSeries &p) = 0;
	virtual bool	operator ==(CCardSeries &p)= 0;

public:
	vector<CCard>	m_Cards;

	char            m_CardType;
	
};

bool Lower(CCard &c1,CCard &c2); //供比较使用


#endif //__INC_CARD_SERIES_DEF_H__
