/*************************************************************
*	Module:	CardCompareImpl.h
*
*	Description:
*		���͵Ĵ�С�Ƚ��㷨��װ���ṩ�˶����������͵Ĵ�С�Ƚ��㷨
*	ʵ�֡�

*	Author:
		David.Zhu
*	Date:
*		2007-2-12
*************************************************************/
#ifndef __INC_CARD_COMPARE_IMPL_DEF_H__
#define __INC_CARD_COMPARE_IMPL_DEF_H__

class CCardSeries;
class ICardCompare
{
public:
	virtual ~ICardCompare(){};

	//����ֵ���壺
	//  1	��seriesA > seriesB
	//	-1	��seriesA < seriesB
	//	0	��seriesA = seriesB
	//	-2	���������޷��Ƚϣ����Ͳ�����
	virtual int	Exec(CCardSeries *seriesA,CCardSeries *seriesB)=0;
};


class CCardCompareImpl:public ICardCompare
{
public:
	 CCardCompareImpl(){};
	~CCardCompareImpl(){};
	
	virtual int	Exec(CCardSeries *seriesA,CCardSeries *seriesB);
};
#endif //__INC_CARD_COMPARE_IMPL_DEF_H__