#include "CardCompareImpl.h"
#include "CardSeries.h"
#include "Card.h"

#include <assert.h>

//��ʼ�������,1��ʾ���ڣ�0��ʾ���ԱȽϣ�-1��ʾС�ڣ�-2��ʾ���ɱȽ�
static char LordRuleTable[12][12]=
{
	{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},	//CardSeries_Type_Unknown
	{-2,-2, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1},	//CardSeries_Type_Rocket
	{-2,-1, 0, 1, 1, 1, 1, 1 ,1, 1, 1, 1},	//CardSeries_Type_Bomb
	{-2,-1,-1, 0,-2,-2,-2,-2,-2,-2,-2,-2},	//CardSeries_Type_Single
	{-2,-1,-1,-2, 0,-2,-2,-2,-2,-2,-2,-2},	//CardSeries_Type_Double
	{-2,-1,-1,-2,-2, 0,-2,-2,-2,-2,-2,-2},	//CardSeries_Type_TriCard
	{-2,-1,-1,-2,-2,-2, 0,-2,-2,-2,-2,-2},	//CardSeries_Type_TriPlusOne
	{-2,-1,-1,-2,-2,-2,-2, 0,-2,-2,-2,-2},	//CardSeries_Type_SingleSeries
	{-2,-1,-1,-2,-2,-2,-2,-2, 0,-2,-2,-2},	//CardSeries_Type_DoubleSeries
	{-2,-1,-1,-2,-2,-2,-2,-2,-2, 0,-2,-2},	//CardSeries_Type_TriSeries
	{-2,-1,-1,-2,-2,-2,-2,-2,-2,-2, 0,-2},	//CardSeries_Type_PlanPlusWing
	{-2,-1,-1,-2, 0,-2,-2,-2,-2,-2,-2, 0},	//CardSeries_Type_FourPlusTwo
};

//����ֵ���壺
//  1	��seriesA > seriesB
//	-1	��seriesA < seriesB
//	0	��seriesA = seriesB
//	-2	���������޷��Ƚϣ����Ͳ�����	
int	CCardCompareImpl::Exec(CCardSeries *seriesA,CCardSeries *seriesB)
{
	if(NULL==seriesA || NULL== seriesB)
		return -2;

	//ȷ��������ȷ
	assert(seriesA->valid());
	assert(seriesB->valid());

	int  ret=-2;
	int  t1 = seriesA->type(); int t2 = seriesB->type();
	char compare=LordRuleTable[seriesA->type()][seriesB->type()];
	
	do
	{
		if(1==compare || -1==compare)
		{
			ret=(int)compare;
			break;
		}

		//ͬ���͵��Ʊ���Ҫ��������ͬ���ܱȽ�
		if(0==compare)
		{
			if(seriesA->size()==seriesB->size())
			{
				ret=(*seriesA)>(*seriesB)?1:((*seriesA)<(*seriesB))?-1:0;
			}else{
				ret  = -2;  //���ɱȽ�
			}
		}

	}while(0);

	return ret;
}