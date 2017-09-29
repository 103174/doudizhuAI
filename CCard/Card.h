#ifndef __INC_CARD_DEF_H__
#define __INC_CARD_DEF_H__

class CCard
{
public:
	CCard();
	CCard(const CCard &card);
	CCard(const char color,const char value);
    CCard(const int index);
	~CCard(){};

	inline void Color(const char color){m_btColor=color;};
	inline char Color() const{return m_btColor;};

	void Value(const char  value){m_btValue=value;};
	char Value() const{return m_btValue;};
    char LogicValue(); 

	CCard&	operator =(const CCard &card);
	bool	operator <(const CCard &card);
	bool	operator >(const CCard &card);
	bool	operator ==(const CCard &card);

public:
	char  m_btColor;	//花色;  0:未知花色，1:方块， 2:梅花， 3：红桃 ， 4：黑桃
	char  m_btValue;	//面值;  3,4,5,6,7,8,9,10,11(J),12(Q),13(K),14(A),15(2),16(小王八),17（大王八)
};


#endif //__INC_CARD_DEF_H__