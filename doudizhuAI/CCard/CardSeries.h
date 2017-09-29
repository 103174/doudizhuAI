/*****************************************************
*
*		Module: CardSeries.h

*		Description:
*				�����������͵ķ�װ����Щ����һ��
         ����һ�Ż�������϶��ɵġ�

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
		CardSeries_Type_Unknown		=0x00,	//δ֪����
		CardSeries_Type_Rocket		=0x01,	//�����˫����������С������������
		CardSeries_Type_Bomb		=0x02,	//ը��������ͬ��ֵ�ƣ����ĸ�7��
		CardSeries_Type_Single		=0x03,	//���ţ��������5��
		CardSeries_Type_Double		=0x04,	//���ƣ���ͬ��ֵ�������ƣ���÷��4+����4��
		CardSeries_Type_TriCard		=0x05,	//�����ƣ���ֵ��ͬ�������ƣ�������J��
		CardSeries_Type_TriPlusOne	=0x06,	//����һ����ֵ��ͬ��������+һ�ŵ��ƻ�һ����
		CardSeries_Type_SingleSeries=0x07,	//��˳�����Ż������������ƣ���34567��78910JQK)����������2���˫��
		CardSeries_Type_DoubleSeries=0x08,  //˫˳�����Ի������������ƣ���334455��7788991010JJ������������2���˫��
		CardSeries_Type_TriSeries	=0x09,	//��˳���������������������ƣ���333444��555666777������������2���˫��
		CardSeries_Type_PlanPlusWing=0x0A,	//�ɻ��������˳+ͬ�����ĵ��ƣ���ͬ�����Ķ��ƣ�����444555+79��333444555+7799JJ
		CardSeries_Type_FourPlusTwo	=0x0B	//�Ĵ�����������+�����ƣ�ע�⣺�Ĵ�������ը������5555+3+8��4444+55+77
	};

	bool   Init(CCard *pCards, int nSize); //��ʼ��һ����

	bool			valid() const;		//�ж����͵��Ƿ���ȷ
	inline int		size()  const{
		return m_Cards.size();
	}

	CCard&			Card(int index);
	CCard&	operator [](int index) ;	
	CCardSeries&	operator = ( CCardSeries &CardSeries);

	virtual CCardSeries*    clone() = 0;	//���͵Ŀ�¡����
	virtual void	sort() = 0;	 //���ƽ�������

	
	virtual BYTE type()
	{
		return m_CardType;
	}
	
	virtual bool	operator <(CCardSeries &p) = 0;	//�Ƚ�ͬ�����͵Ĵ�С
	virtual bool	operator >(CCardSeries &p) = 0;
	virtual bool	operator ==(CCardSeries &p)= 0;

public:
	vector<CCard>	m_Cards;

	char            m_CardType;
	
};

bool Lower(CCard &c1,CCard &c2); //���Ƚ�ʹ��


#endif //__INC_CARD_SERIES_DEF_H__
