#ifndef __INC_CCardSeriesIdentifierImpl_DEF_H__
#define __INC_CCardSeriesIdentifierImpl_DEF_H__

/*********************************************
*	Module: CardSeriesIdentifierImpl.h

*	Description:
*			定义了牌型确定算法接口并提供了一个
*        默认实现。
*	Author:
			David.Zhu
*	Date:	
*			2007-2-12
*********************************************/

#pragma 
#include"Utils.h"

//Pre-declaration
class CCard;
class CCardSeries;

typedef long LONG;
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;

typedef LONG DWORD_PTR;

#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define LOWORD(l)           ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l)           ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))


class ICardSeriesIdentifier
{
public:
	virtual ~ICardSeriesIdentifier(){};

	//返回值类型定义：
	//  CardSeries_Type_XXXX
	virtual char	Exec(CCard *pCard,int size)=0;
};


class CCardSeriesIdentifierImpl:public ICardSeriesIdentifier
{
public:
	CCardSeriesIdentifierImpl(){};
	virtual ~CCardSeriesIdentifierImpl(){};

	DECLARE_SINGLETON(CCardSeriesIdentifierImpl);

	virtual char	Exec(CCard *pCard,int size);

protected:
	WORD 	CalcVectorModule(char *pVec,int size);
	char	GetSeriesLength(char *pVec,int size,int threshold);
	bool	IsVectorFeature(char *pVec,int size,int threshold,int cnt);
};

#endif