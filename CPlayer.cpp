#include "Card.h"
#include "Cardseries.h"
#include "CardCompareImpl.h"
#include "CardseriesIdentifierImpl.h"
#include "CardSeries_TriPlusOneCard.h"
#include "CardSeries_Bomb.h"
#include "CardSeries_Rocket.h"
#include "CardSeries_SingleCard.h"
#include "CardSeries_SingleSeriesCard.h"
#include "CardSeries_TriCard.h"
#include "CardSeries_TriPlusOneCard.h"
#include "CardSeries_TriSeriesCard.h"
#include "CardSeriesFactory.h"
#include "CardSeriesIdentifierImpl.h"
#include "CardSeries_DoubleCard.h"
#include "CardSeries_Bomb.h"
#include "CardSeries_DoubleSeriesCard.h"
#include "CardSeriesFactory.h"

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class CPlayer {

public:
	CPlayer() 
	{
		weight[0] = 0,		// Cardseries_Type_Unknown
		weight[1] = 40,		// Cardseries_Type_Rocket
		weight[2] = 20,		// Cardseries_Type_Bomb
		weight[3] = -2,		// Cardseries_Type_Single
		weight[4] = 3,		// Cardseries_Type_Double
		weight[5] = 6,		// Cardseries_Type_TriCard
		weight[6] = 0,		// Cardseries_Type_TriPlusOne
		weight[7] = 2,		// Cardseries_Type_Singleseries
		weight[8] = 2,		// Cardseries_Type_Doubleseries
		weight[9] = 3,		// Cardseries_Type_Triseries
		weight[10] = 0,		// Cardseries_Type_PlanPlusWing
		weight[11] = 0;		// Cardseries_Type_FourPlusTwo
				// king 8 KING 12 Z 6 A 4

	}
	static CPlayer& getInstance() {
		static CPlayer instance;
		return instance;
	}

	bool IsCallLord(vector<bool> call_result, vector<CCard> cards) {
		init_structures(cards);
		check_and_divide();
		return cal_weight_of_cards() > 30;
	}

	vector<CCard> ConsumerCard(
		vector<CCard> MyCard, vector<CCard> history[3],
		vector<CCard> LordCards, vector<CCard> LastConsumerCard, 
		char LastConsumerPlayer, char lord)
	{
		init_structures(MyCard);
		check_and_divide();
		
		if(LastConsumerCard.empty()) {
			return greedy_attack();
		}
		if(!LastConsumerPlayer) {
			return greedy_attack();
		}

		static CCard last[20];
		for(int i = 0, sz = LastConsumerCard.size(); i < sz; i++)
			last[i] = LastConsumerCard[i];
		char type = identifier.Exec(last, int(LastConsumerCard.size()));
		//CCardseries cards;
		
		CCardSeries* cards = factory.CreateCardSeries(type);
		cards->Init(last, int(LastConsumerCard.size()));

		if(!lord) {		/// be the lord
			return greedy_consume(type, *cards);
		} else {
			return greedy_consume(type, *cards);
		}
		delete cards;
	}

private:

	enum
	{
		Cardseries_Type_Unknown		=0x00,
		Cardseries_Type_Rocket		=0x01,
		Cardseries_Type_Bomb		=0x02,
		Cardseries_Type_Single		=0x03,
		Cardseries_Type_Double		=0x04,
		Cardseries_Type_TriCard		=0x05,
		Cardseries_Type_TriPlusOne	=0x06,
		Cardseries_Type_Singleseries=0x07,
		Cardseries_Type_Doubleseries=0x08,
		Cardseries_Type_Triseries	=0x09,
		Cardseries_Type_PlanPlusWing=0x0A,
		Cardseries_Type_FourPlusTwo	=0x0B
	};

	
	/****** ** structures ** *********************************************************************************************/
	vector<CCard> mycard;
	#define maxv (20)
	int value_counter[maxv];	/// can be feature vector, to help calculate the WEIGHT of remaining cards
	int single_dog[maxv];		/// the real single card, should be a trouble
	#define maxs (0x0C)
	vector<CCardSeries*> series[maxs];
    int weight[maxs];
	/*
	const int weight[maxs] = {
		0, 		// Cardseries_Type_Unknown
		40,		// Cardseries_Type_Rocket
		20,		// Cardseries_Type_Bomb
		-2,		// Cardseries_Type_Single
		3,		// Cardseries_Type_Double
		6,		// Cardseries_Type_TriCard
		0,		// Cardseries_Type_TriPlusOne
		2,		// Cardseries_Type_Singleseries
		2,		// Cardseries_Type_Doubleseries
		3,		// Cardseries_Type_Triseries
		0,		// Cardseries_Type_PlanPlusWing
		0		// Cardseries_Type_FourPlusTwo
				// king 8 KING 12 Z 6 A 4
	};*/

	CCardSeriesIdentifierImpl identifier;
	CCardSeriesFactory factory;
	
	/****** ** functions ** **********************************************************************************************/
	/**********************
	 ** About Policy
	 */
	vector<CCard> greedy_attack()
	{
		vector<CCard> ret;
		if(!series[Cardseries_Type_Singleseries].empty()) {
			for(int i = 0, sz = series[Cardseries_Type_Singleseries].size(); i < sz; i++) {
				for(int j = 0, len = series[Cardseries_Type_Singleseries][i]->m_Cards.size(); j < len; j++) {
					ret.push_back( series[Cardseries_Type_Singleseries][i]->m_Cards[j] );
				}
				return ret;
			}
		}
		if(!series[Cardseries_Type_Doubleseries].empty()) {
			for(int i = 0, sz = series[Cardseries_Type_Doubleseries].size(); i < sz; i++) {
				for(int j = 0, len = series[Cardseries_Type_Doubleseries][i]->m_Cards.size(); j < len; j++) {
					ret.push_back( series[Cardseries_Type_Doubleseries][i]->m_Cards[j] );
				}
				return ret;
			}			
		}
		/// try construct plane with wing
		if(!series[Cardseries_Type_Triseries].empty()) {	/// important
			for(int i = 0, sz = series[Cardseries_Type_Triseries].size(); i < sz; i++) {
				for(int j = 0, len = series[Cardseries_Type_Triseries][i]->m_Cards.size(); j < len; j++) {
					ret.push_back( series[Cardseries_Type_Triseries][i]->m_Cards[j] );
				}
				break;
			}
			int single_num = ret.size() / 3;
			if(series[Cardseries_Type_Single].size() + series[Cardseries_Type_Double].size() * 2 < single_num)
				return ret;
			for(int i = 0, sz = series[Cardseries_Type_Single].size(); i < sz; i++) {
				ret.push_back( series[Cardseries_Type_Single][i]->m_Cards[0] );
				single_num--;
				if(!single_num) break;
			} 
			if(!single_num) return ret;
			for(int i = series[Cardseries_Type_Double].size() - 1; i >= 0; i--) {
				ret.push_back( series[Cardseries_Type_Double][i]->m_Cards[0] );
				single_num--;
				if(!single_num) break;
				ret.push_back( series[Cardseries_Type_Double][i]->m_Cards[1] );
				single_num--;
				if(!single_num) break;				
			} 
			return ret;
		}
		/// try 3 + 1 or 3 + 2 or 3
		if(!series[Cardseries_Type_TriCard].empty()) {
			for(int i = 0, sz = series[Cardseries_Type_TriCard].size(); i < sz; i++) {
				for(int j = 0, len = series[Cardseries_Type_TriCard][i]->m_Cards.size(); j < len; j++) {
					ret.push_back( series[Cardseries_Type_TriCard][i]->m_Cards[j] );
				}
				break;
			}
			if(!series[Cardseries_Type_Single].empty()) {
				for(int i = 0, sz = series[Cardseries_Type_Single].size(); i < sz; i++) {
					ret.push_back( series[Cardseries_Type_Single][i]->m_Cards[0] );
					break;
				}
			}
			if(ret.size() > 3) return ret;
			if(!series[Cardseries_Type_Double].empty()) {
				for(int i = series[Cardseries_Type_Double].size() - 1; i >= 0; i--) {
					ret.push_back( series[Cardseries_Type_Double][i]->m_Cards[0] );
					ret.push_back( series[Cardseries_Type_Double][i]->m_Cards[1] );
					break;
				}
			}
			return ret;
		}

		/// single card, out the least
		if(!series[Cardseries_Type_Single].empty()) {
			for(int i = 0, sz = series[Cardseries_Type_Single].size(); i < sz; i++) {
				ret.push_back( series[Cardseries_Type_Single][i]->m_Cards[0] );
				return ret;
			}			
		}
	

		for(int i = Cardseries_Type_FourPlusTwo; i > 0; i--) {
			for(int j = 0, sz = series[i].size(); j < sz; j++) {
				for(int k = 0, len = series[i][j]->m_Cards.size(); k < len; k++) {
					ret.push_back(series[i][j]->m_Cards[k]);
				}
				return ret;
			}
		}

		// return NULL; 
		vector<CCard> tmp;
		return tmp; 	/// impossible
	}
	vector<CCard> greedy_consume(char type, CCardSeries &CardSeries)
	{
		vector<CCard> null;
		vector<CCard> ret;
		if(type == Cardseries_Type_TriPlusOne) {	/// need to combine		OK
			
			CCardSeries_TriPlusOneCard *pp = (CCardSeries_TriPlusOneCard*)&CardSeries;
			CardSeries.sort();
			int bt_Base = pp->bt_Base.m_btValue;
			for(int i = series[Cardseries_Type_TriCard].size(); i >= 0; i--) {
				if(series[Cardseries_Type_TriCard][i]->m_Cards[0] > bt_Base) {
					ret.push_back( series[Cardseries_Type_TriCard][i]->m_Cards[0] );
					ret.push_back( series[Cardseries_Type_TriCard][i]->m_Cards[1] );
					ret.push_back( series[Cardseries_Type_TriCard][i]->m_Cards[2] );
					break;
				}
			}
			if(ret.empty()) return null;
			for(int i = 0, sz = series[Cardseries_Type_Single].size(); i < sz; i++) {
				ret.push_back( series[Cardseries_Type_Single][i]->m_Cards[0] );
				break;
			}
			if(ret.size() == 4) return ret;
			for(int i = series[Cardseries_Type_Double].size() - 1; i >= 0; i--) {
				for(int j = 0, len = series[Cardseries_Type_Double][j]->m_Cards.size(); j < len; j++) {
					ret.push_back( series[Cardseries_Type_Double][j]->m_Cards[j] );
					break;
				}
				break;
			}

			if(ret.size() == 4) return ret;
			return null;

		} else if(type == Cardseries_Type_PlanPlusWing) { /// need to combine	OK

			static int plane_vis[maxv];
			memset(plane_vis, 0, sizeof(plane_vis));
			for(int i = 0, sz = CardSeries.m_Cards.size(); i < sz; i++) {
				plane_vis[CardSeries.m_Cards[i].m_btValue]++;
			}
			int _3_len = 0, _3_value = 0, plane_type = 0;
			for(int i = 0; i < maxv; i++) if(plane_vis[i] > 0) {
				if(plane_vis[i] == 3) {
					_3_len++;
					_3_value = max(_3_value, i);
				} else {
					plane_type = plane_vis[i];
				}
			}
			for(int i = series[Cardseries_Type_TriCard].size() - 1; i >= 0; i++) {
				if( series[Cardseries_Type_TriCard][i]->m_Cards.size() >= _3_len && series[Cardseries_Type_TriCard][i]->m_Cards[0] > _3_value ) {
					for(int j = 0, len = series[Cardseries_Type_TriCard][i]->m_Cards.size(); j < len; j++) {
						ret.push_back(series[Cardseries_Type_TriCard][i]->m_Cards[j]);
					}
					break;
				}
			}
			if(ret.empty()) return null;
			int need = _3_len;
			if(plane_type == 1) {
				/// if _3_len - single is odd; then...
				for(int i = 0, sz = series[Cardseries_Type_Single].size(); i < sz; i++) {
					ret.push_back( series[Cardseries_Type_Single][i]->m_Cards[0] );
					need--;
					if(!need) break;
				}
				if(need) for(int i = series[Cardseries_Type_Double].size() - 1; i >= 0; i--) {
					for(int j = 0, len = series[Cardseries_Type_Double][j]->m_Cards.size(); j < len; j++) {
						ret.push_back( series[Cardseries_Type_Double][j]->m_Cards[j] );
						need--;
						if(!need) break;
					}
					if(!need) break;
				}
				if(need) return null;
				else return ret;
			} else {
				///
				if( series[Cardseries_Type_Double].size() < need) return null;
				for(int i = series[Cardseries_Type_Double].size() - 1; i >= 0; i--) {
					for(int j = 0, len = series[Cardseries_Type_Double][j]->m_Cards.size(); j < len; j++) {
						ret.push_back( series[Cardseries_Type_Double][j]->m_Cards[j] );
					}
					need--;
					if(!need) break;
				}
				return ret;
			}

 		} else if(type == Cardseries_Type_FourPlusTwo) {	/// need to combine		OK

			/// throw a bomb
			for(int i = series[Cardseries_Type_Bomb].size() - 1; i >= 0; i++) {
				for(int j = 0, len = series[Cardseries_Type_Bomb][i]->m_Cards.size(); j > len; j++)
					ret.push_back( series[Cardseries_Type_Bomb][i]->m_Cards[j] );
				return ret;
			}
			return null;

		} else if(type >= Cardseries_Type_Singleseries) {	/// need to draw  difficult

			int series_len = CardSeries.m_Cards.size();
			for(int i = 0, sz = series[type].size(); i < sz; i++) {
				if( series[type][i]->m_Cards.size() >= series_len ) {
					for(int j = 0; j < series_len; j++) {
						ret.push_back( series[type][i]->m_Cards[j] );
					}
					break;
				}
				if(ret.size()) break;
			}
			if( ret[ret.size() - 1] > CardSeries.m_Cards[series_len - 1] )
				return ret;
			return null;

		} else {	/// simple	OK

			for(int i = series[type].size() - 1; i >= 0; i++) {
				if( (*series[type][i]) > CardSeries ) {
					for(int j = 0, len = series[type][i]->m_Cards.size(); j < len; j++)
						ret.push_back( series[type][i]->m_Cards[j] );
					return ret;
				}
			}
			return null;
		}
	}

	/**********************
	 ** About Create Constructures
	 */

	void init_structures(const vector<CCard>& MyCard) 
	{
		memset(value_counter, 0, sizeof(value_counter));
		memset(single_dog, 0, sizeof(single_dog));
		for(int i = 0; i < maxs; i++) {
			series[i].clear();
		}
		mycard = MyCard;
		sort(mycard.begin(), mycard.end());
		for(int i = 0, sz = mycard.size(); i < sz; i++) {
			value_counter[mycard[i].m_btValue]++;
		}
	}
	/// 3,4,5,6,7,8,9,10,11(J),12(Q),13(K),14(A),15(2),16(king),17(KING)
	#define J (11)
	#define Q (12)
	#define K (13)
	#define A (14)	
	#define Z (15)
	#define king (16)
	#define KING (17)
	/// calculate weight depending on the 'series'
	int cal_weight_of_cards() 
	{
		int w = 0;
		for(int i = Cardseries_Type_Rocket, sz; i <= Cardseries_Type_FourPlusTwo; i++) {
			if(series[i].empty()) continue;
			else sz = series[i].size();
			if(i >= Cardseries_Type_Singleseries) {
				for(int j = 0, len; j < sz; j++) {
					len = series[i][j]->m_Cards.size();
					w += len * weight[i];
				}
			} else {
				w += weight[i] * sz;
			}
		}
		w += value_counter[king] * 8;
		w += value_counter[KING] * 12;
		if(series[Cardseries_Type_Rocket].empty()) w += value_counter[Z] * 6;
		else w += value_counter[Z] * 8;
		w += value_counter[A] * 4;
		return w;
	}

	void check_and_divide() 
	{
		for(int i = Cardseries_Type_Unknown; i <= Cardseries_Type_FourPlusTwo; i++) {
			switch(i) {
				case Cardseries_Type_Rocket:
				pickout_rocket(series[Cardseries_Type_Rocket], mycard);
				break;
				case Cardseries_Type_Bomb:
				pickout_bomb(series[Cardseries_Type_Bomb], mycard);
				break;
				case Cardseries_Type_Single:
				/// to be calculate
				break;
				case Cardseries_Type_Double:
				pickout_double(series[Cardseries_Type_Double], mycard);
				break;
				case Cardseries_Type_TriCard:
				pickout_trible(series[Cardseries_Type_TriCard], mycard);
				break;
				case Cardseries_Type_TriPlusOne:
				/// to be calculate
				break;
				case Cardseries_Type_Singleseries:
				pickout_single_series(series[Cardseries_Type_Singleseries], mycard);
				break;
				case Cardseries_Type_Doubleseries:
				pickout_double_series(series[Cardseries_Type_Doubleseries], mycard);
				break;
				case Cardseries_Type_Triseries:
				pickout_trible_series(series[Cardseries_Type_Triseries], mycard);
				break;
				case Cardseries_Type_PlanPlusWing:
				/// to be calculate
				break;
				case Cardseries_Type_FourPlusTwo:
				/// to be calculate
				break;
			}
		}
		pickout_single_dog(series[Cardseries_Type_Single], mycard);
	}
	/// be called for check_and_divide
	void pickout_rocket(vector<CCardSeries*>& v_rocket, const vector<CCard>& mycard) {
		if(value_counter[king] && value_counter[KING]) {
			CCardSeries_Rocket rocket;
			int sz = mycard.size();
			rocket.m_Cards.push_back(mycard[sz-1]);
			rocket.m_Cards.push_back(mycard[sz-2]);
			v_rocket.push_back(rocket.clone());
		}
	}
	void pickout_bomb(vector<CCardSeries*>& v_bomb, const vector<CCard>& mycard) {
		for(int i = 0; i < maxv; i++) if(value_counter[i] >= 4) {
			for(int j = 0, sz = mycard.size(); j < sz; j++) {
				if(mycard[j].m_btValue == i) {
					CCardSeries_Bomb bomb;
					bomb.m_Cards.push_back(mycard[j]);   single_dog[j]++;
					bomb.m_Cards.push_back(mycard[j+1]); single_dog[j+1]++;
					bomb.m_Cards.push_back(mycard[j+2]); single_dog[j+2]++;
					bomb.m_Cards.push_back(mycard[j+3]); single_dog[j+3]++;
					v_bomb.push_back(bomb.clone());
					break;
				}
			}
		}
	}
	void pickout_double(vector<CCardSeries*>& v_double, const vector<CCard>& mycard) {
		for(int i = 0; i < maxv; i++) if(value_counter[i] >= 2) {
			for(int j = 0, sz = mycard.size(); j < sz; j++) {
				if(mycard[j].m_btValue == i) {
					CCardSeries_Double _double;
					_double.m_Cards.push_back(mycard[j]);   single_dog[j]++;
					_double.m_Cards.push_back(mycard[j+1]); single_dog[j+1]++;
					v_double.push_back(_double.clone());
					break;
				}				
			}
		}
	}
	void pickout_trible(vector<CCardSeries*>& v_trible, const vector<CCard>& mycard) {
		for(int i = 0; i < maxv; i++) if(value_counter[i] >= 3) {
			for(int j = 0, sz = mycard.size(); j < sz; j++) {
				if(mycard[j].m_btValue == i) {
					CCardSeries_TriCard trible;
					trible.m_Cards.push_back(mycard[j]);   single_dog[j]++;
					trible.m_Cards.push_back(mycard[j+1]); single_dog[j+1]++;
					trible.m_Cards.push_back(mycard[j+2]); single_dog[j+2]++;
					v_trible.push_back(trible.clone());
					break;
				}				
			}
		}
	}
	void pickout_single_series(vector<CCardSeries*>& v_single_series, const vector<CCard>& mycard) {
		int cp_value_counter[maxv];	/// 复制牌面计数器
		for(int i = 0; i < maxv; i++)
			cp_value_counter[i] = value_counter[i];
		int vis[maxv];
		memset(vis, 0, sizeof(vis));
		for(;;) {
			bool found = false;
			for(int l = A, r; l >= 7; l--) if(cp_value_counter[l] > 0) {	/// 从尖到7枚举，每种牌面向后数若干次
				for(r = l - 1; r >= 3; r--) {		/// r将会定位到第一次断掉的位置，无论是超出3还是该面值数量为0
					if(cp_value_counter[r] <= 0) break;
				}
				if(l - r >= 5) {	/// 这样l到r之间为顺子牌面的位置，此时需要提取出该牌面对应的CCard对象
					found = true;
					 
					CCardSeries_SingleSeriesCard single_series;
					
					for(int i = l; i > r; i--) {
						cp_value_counter[i]--;
						for(int j = 0, sz = mycard.size(); j < sz; j++) 	/// 提取的方法很暴力，遍历mycard，找到后就提取
						if(mycard[j].m_btValue == i && !vis[j]) {
							single_series.m_Cards.push_back(mycard[j]);   single_dog[j]++;	/// 需要注意single_dog的计数，表明该CCard不落单
							vis[j] = 1;	/// 注意增加判重，避免该CCard被重复提取，因为顺子是连续的，我们只提取最长的即可，需要时可以拆分
							break;
						}
					}
					v_single_series.push_back(single_series.clone());
				}
			}
			if(!found) break;	/// 这样做若干轮，直到不存在顺子退出
		}
		return ;
	}
	void pickout_double_series(vector<CCardSeries*>& v_double_series, const vector<CCard>& mycard) {
		int cp_value_counter[maxv];
		for(int i = 0; i < maxv; i++)
			cp_value_counter[i] = value_counter[i];
		int vis[maxv];
		memset(vis, 0, sizeof(vis));
		for(;;) {
			bool found = false;
			for(int l = A, r; l >= 5; l--) if(cp_value_counter[l] >= 2) {
				for(r = l - 1; r >= 3; r--) {
					if(cp_value_counter[r] < 2) break;
				}
				if(l - r >= 3) {
					found = true;
					
					CCardSeries_DoubleSeriesCard double_series;
					for(int i = l; i > r; i--) {
						cp_value_counter[i] -= 2;
						for(int j = 0, t = 2, sz = mycard.size(); j < sz; j++) 
						if(mycard[j].m_btValue == i && !vis[j]) {
							double_series.m_Cards.push_back(mycard[j]);   single_dog[j]++;
							vis[j] = 1;
							t--;
							if(!t) break;
						}
					}
					v_double_series.push_back(double_series.clone());
				}
			}
			if(!found) break;
		}
		return ;
	}
	void pickout_trible_series(vector<CCardSeries*>& v_trible_series, const vector<CCard>& mycard) {
		int cp_value_counter[maxv];
		for(int i = 0; i < maxv; i++)
			cp_value_counter[i] = value_counter[i];
		int vis[maxv];
		memset(vis, 0, sizeof(vis));

		for(int l = A, r; l >= 4; l--) if(cp_value_counter[l] >= 3) {
			for(r = l - 1; r >= 3; r--) {
				if(cp_value_counter[r] < 3) break;
			}
			if(l - r >= 2) {
				CCardSeries_TriSeriesCard trible_series;
				for(int i = l; i > r; i--) {
					cp_value_counter[i] -= 3;
					for(int j = 0, t = 3, sz = mycard.size(); j < sz; j++) 
					if(mycard[j].m_btValue == i && !vis[j]) {
						trible_series.m_Cards.push_back(mycard[j]);   single_dog[j]++;
						vis[j] = 1;
						t--;
						if(!t) break;
					}
				}
				v_trible_series.push_back(trible_series.clone());
			}
		}
		return ;
	}
	void pickout_single_dog(vector<CCardSeries*>& v_single_dog, const vector<CCard>& mycard) {
		for(int i = 0, sz = mycard.size(); i < sz; i++) {
			if(mycard[i].m_btValue <= KING && !single_dog[i]) {
				CCardSeries_Single single;
				single.m_Cards.push_back(mycard[i]);
				v_single_dog.push_back(single.clone());
			}
		}
	}
	/// check_and_divide end

};



int main()
{
	return 0;
}